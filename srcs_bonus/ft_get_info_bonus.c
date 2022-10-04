/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:41:59 by aleferra          #+#    #+#             */
/*   Updated: 2022/02/16 11:49:50 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static t_pos	ft_take_pos_init(char **map, int c)
{
	int		line;
	int		col;
	t_pos	perso;

	line = -1;
	perso.pos_x = -1;
	perso.pos_y = -1;
	perso.direction = 0;
	while (map[++line])
	{
		col = -1;
		while (map[line][++col])
		{	
			if (map[line][col] == c)
			{
				perso.pos_y = line;
				perso.pos_x = col;
				return (perso);
			}
		}
	}
	return (perso);
}

static t_pos	ft_add_enemy(t_vars vars)
{
	int		line;
	int		col;
	int		caase;
	t_pos	enemy;

	enemy.pos_x = -1;
	enemy.pos_y = -1;
	enemy.direction = 0;
	caase = 0;
	while (enemy.pos_x == -1)
	{
		line = rand() % (vars.line_map - 1);
		col = rand() % (vars.col_map - 1);
		if (vars.map[line][col] != '1' && vars.map[line][col] != 'P')
		{
			enemy.pos_x = line;
			enemy.pos_y = col;
		}	
	}
	return (enemy);
}

static t_compo	*ft_take_compo(char **map, int c)
{
	int		line;
	int		col;
	t_compo	*chaine;

	chaine = NULL;
	line = -1;
	while (map[++line])
	{
		col = -1;
		while (map[line][++col])
		{
			if (map[line][col] == c)
				chaine = ft_add_back(&chaine, ft_add_new_comp(line, col));
		}
	}
	return (chaine);
}

int	ft_nb_key(t_vars vars)
{
	t_compo	*pieces;
	int		index;

	pieces = vars.pieces;
	index = 0;
	if (!pieces)
		return (0);
	while (pieces)
	{
		index++;
		pieces = pieces->next;
	}
	return (index);
}

t_vars	ft_get_info(t_vars vars, char *str)
{
	vars.height = 100;
	vars.width = 100;
	vars.line_map = ft_nb_line(str);
	vars.col_map = ft_nb_col(vars.map);
	vars.perso = ft_take_pos_init(vars.map, 'P');
	vars.escape = ft_take_pos_init(vars.map, 'E');
	vars.pieces = ft_take_compo(vars.map, 'C');
	vars.enemy = ft_add_enemy(vars);
	vars.nbkey = ft_nb_key(vars);
	vars.nbpas = 0;
	vars.move = 0;
	return (vars);
}
