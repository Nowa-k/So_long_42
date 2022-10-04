/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:52:50 by aleferra          #+#    #+#             */
/*   Updated: 2022/02/07 17:55:59 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_reader(int fd)
{
	char	*res;
	int		reader;

	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!res)
		return (NULL);
	reader = read(fd, res, BUFFER_SIZE);
	if (reader < 0)
	{
		free (res);
		return (NULL);
	}
	res[reader] = '\0';
	return (res);
}

char	*ft_joinbuff(char *buff, int fd)
{
	char	*nextbuff;
	char	*res;

	nextbuff = ft_reader(fd);
	if (!nextbuff)
		return (NULL);
	if (!nextbuff[0])
	{
		free(nextbuff);
		return (buff);
	}
	if (!buff)
		return (nextbuff);
	res = ft_strjoin(buff, nextbuff);
	free (buff);
	free (nextbuff);
	return (res);
}

char	*ft_majbuff(char *buff, char *line)
{
	char	*res;
	size_t	lenbuff;
	size_t	lenline;

	if (!buff || !line)
		return (NULL);
	lenbuff = ft_strlen(buff);
	lenline = ft_strlen(line);
	if (lenbuff == lenline)
	{
		free(buff);
		return (NULL);
	}
	res = ft_substr(buff, lenline, lenbuff);
	free (buff);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buff[4096];
	char		*res;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	res = 0;
	if (ft_strchr(buff[fd], '\n') == -1)
	{
		len = ft_strlen(buff[fd]);
		buff[fd] = ft_joinbuff(buff[fd], fd);
		if (len == ft_strlen(buff[fd]))
			res = ft_substr(buff[fd], 0, len);
	}
	if (!buff[fd])
		return (NULL);
	if (!res && ft_strchr(buff[fd], '\n') != -1)
		res = ft_substr(buff[fd], 0, ft_strchr(buff[fd], '\n') + 1);
	if (res)
	{
		buff[fd] = ft_majbuff(buff[fd], res);
		return (res);
	}
	return (get_next_line(fd));
}
