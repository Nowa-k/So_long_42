/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:03:34 by aleferra          #+#    #+#             */
/*   Updated: 2022/01/31 16:18:39 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s1)
{
	size_t	index;

	index = 0;
	if (!s1)
		return (0);
	while (s1[index])
		index++;
	return (index);
}

int	ft_strchr(char *s1, int c)
{
	int	index;

	index = 0;
	if (!s1)
		return (-1);
	while (s1[index])
	{
		if (s1[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

char	*ft_substr(char *s1, int start, int end)
{
	char	*res;
	int		index;

	index = 0;
	if (!s1)
		return (NULL);
	if (start >= end)
	{
		res = (char *)malloc(sizeof(char) * (end + 1));
		if (!res)
			return (NULL);
		while (s1[index++])
			res[index] = s1[index];
		res[index] = '\0';
		return (res);
	}
	res = malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	while (start < end)
		res[index++] = s1[start++];
	res[index] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		indexs1;
	int		indexs2;

	indexs1 = -1;
	indexs2 = -1;
	if (!s1 || !s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[++indexs1] && s1)
		res[indexs1] = s1[indexs1];
	while (s2[++indexs2])
		res[indexs1 + indexs2] = s2[indexs2];
	res[indexs1 + indexs2] = '\0';
	return (res);
}
