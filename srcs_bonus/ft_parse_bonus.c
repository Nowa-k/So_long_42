/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:58:28 by aleferra          #+#    #+#             */
/*   Updated: 2022/02/16 11:53:07 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	ft_map_is_rec(char **map)
{
	int	index;
	int	countchar;
	int	lenline;

	lenline = -1;
	index = -1;
	while (map[++index])
	{
		countchar = -1;
		while (map[index][++countchar] && map[index][countchar] != '\n')
			;
		if (lenline != -1 && countchar != lenline)
			return (1);
		if (lenline == -1)
			lenline = countchar;
	}
	return (0);
}

static t_comp	ft_init_comp(void)
{
	t_comp	comp;

	comp.comp = 0;
	comp.perso = 0;
	comp.sortie = 0;
	return (comp);
}

static int	ft_map_have_composant(char **map, int maxline)
{
	int		line;
	int		col;
	t_comp	comp;

	line = -1;
	comp = ft_init_comp();
	while (++line < maxline)
	{
		col = -1;
		while (map[line][++col + 1])
		{
			if (map[line][col] == 'P')
				comp.perso++;
			else if (map[line][col] == 'C')
				comp.comp++;
			else if (map[line][col] == 'E')
				comp.sortie++;
			else if (map[line][col] != '0' && map[line][col] != '1')
				return (1);
		}
	}
	if (comp.perso <= 0 || comp.comp <= 0 || comp.sortie <= 0)
		return (1);
	return (0);
}

static int	ft_is_ber(char *str)
{
	int	index;
	int	err;

	err = 0;
	index = -1;
	while (str[++index])
		;
	if (str[--index] != 'r')
		err++;
	if (str[--index] != 'e')
		err++;
	if (str[--index] != 'b')
		err++;
	if (str[--index] != '.')
		err++;
	if (err > 0)
	{
		ft_putstr_fd("Error\nLe fichier envoyé n'est pas un '.ber'.\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	ft_is_parse(char **map, char *str)
{
	int	line;

	ft_fd_is_invalid(str);
	line = ft_nb_line(str);
	ft_is_ber(str);
	if (ft_map_is_rec(map))
	{
		ft_putstr_fd("Error\nLa map n'est pas rectangulaire.\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_first_last_col(map, line) || ft_first_last_line(map, line))
	{
		ft_putstr_fd("Error\nLa map n'est pas encadrée de mur.\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_map_have_composant(map, line))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("La map contient de mauvais caractères.\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
