/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:41:59 by aleferra          #+#    #+#             */
/*   Updated: 2022/02/07 17:58:41 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_pos	ft_take_pos_init(char **map, int c)
{
	int			line;
	int			col;
	t_pos		perso;

	line = -1;
	perso.pos_x = -1;
	perso.pos_y = -1;
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

static t_compo	*ft_add_new_comp(int x, int y)
{
	t_compo	*new;

	new = malloc(sizeof(t_compo));
	if (!new)
		return (NULL);
	new->pos.pos_x = y;
	new->pos.pos_y = x;
	new->is = 1;
	new->next = NULL;
	return (new);
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
	vars.nbkey = ft_nb_key(vars);
	vars.nbpas = 0;
	return (vars);
}
