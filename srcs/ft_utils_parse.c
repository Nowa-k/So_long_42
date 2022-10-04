/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:00:29 by aleferra          #+#    #+#             */
/*   Updated: 2022/02/16 11:28:57 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_first_last_line(char **map, int line)
{
	int		column;

	column = -1;
	while (map[0][++column] != '\n')
		if (map[0][column] != '1')
			return (1);
	column = -1;
	while (map[line - 1][++column])
		if (map[line - 1][column] != '1')
			return (1);
	return (0);
}

int	ft_first_last_col(char **map, int maxline)
{
	int		line;
	int		col;

	line = -1;
	col = -1;
	while (++line < maxline)
		if (map[line][0] != '1')
			return (1);
	while (map[0][++col] != '\n')
		;
	line = -1;
	while (++line < maxline)
		if (map[line][col - 1] != '1')
			return (1);
	return (0);
}

int	ft_fd_is_invalid(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nLe fd est invalid.\n", 2);
		close(fd);
		exit(EXIT_FAILURE);
		return (1);
	}
	close(fd);
	return (0);
}
