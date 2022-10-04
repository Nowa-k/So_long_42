/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:04:43 by aleferra          #+#    #+#             */
/*   Updated: 2022/02/07 16:37:35 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_file_map(t_vars *vars, char *str)
{
	int		fd;
	int		index;
	char	**map;

	index = -1;
	vars->line_map = ft_nb_line(str);
	map = malloc(sizeof(char *) * (vars->line_map + 1));
	if (!map)
		return (NULL);
	fd = open(str, O_RDONLY);
	while (++index < vars->line_map)
		map[index] = get_next_line(fd);
	map[index] = NULL;
	close(fd);
	return (map);
}
