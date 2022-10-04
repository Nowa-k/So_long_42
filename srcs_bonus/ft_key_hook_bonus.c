/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:58:10 by aleferra          #+#    #+#             */
/*   Updated: 2022/02/07 18:19:18 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_direction(t_vars *vars, int x, int y)
{
	if (y == 1)
		vars->perso.direction = 0;
	else if (y == -1)
		vars->perso.direction = 3;
	else if (x == 1)
		vars->perso.direction = 2;
	else if (x == -1)
		vars->perso.direction = 1;
}

void	ft_move(t_vars *vars, int x, int y)
{
	t_compo	*tmp;

	tmp = vars->pieces;
	if (vars->map[vars->perso.pos_y + y][vars->perso.pos_x + x] == '1')
		return ;
	ft_direction(vars, x, y);
	vars->perso.pos_x += x;
	vars->perso.pos_y += y;
	while (tmp)
	{
		if (vars->perso.pos_y == tmp->pos.pos_y
			&& vars->perso.pos_x == tmp->pos.pos_x
			&& tmp->is == 1)
		{
			tmp->is = 0;
			vars->nbkey--;
		}
		tmp = tmp->next;
	}
	vars->nbpas++;
	if (vars->escape.pos_x == vars->perso.pos_x
		&& vars->escape.pos_y == vars->perso.pos_y
		&& vars->nbkey == 0)
		ft_exit(&vars);
}

int	ft_key_hook(int key_code, t_vars *vars)
{
	if (key_code == KEY_ESC)
		ft_exit(&vars);
	else if (key_code == KEY_RIGHT)
		ft_move(vars, 1, 0);
	else if (key_code == KEY_LEFT)
		ft_move(vars, -1, 0);
	else if (key_code == KEY_FRONT)
		ft_move(vars, 0, -1);
	else if (key_code == KEY_BACK)
		ft_move(vars, 0, 1);
	return (1);
}
