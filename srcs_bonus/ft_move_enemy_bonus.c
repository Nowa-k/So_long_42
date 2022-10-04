/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:02:50 by aleferra          #+#    #+#             */
/*   Updated: 2022/02/07 18:47:30 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_direction_enemy_asset(t_vars *vars, int x, int y)
{
	if (y == 1)
		vars->enemy.direction = 2;
	else if (y == -1)
		vars->enemy.direction = 1;
	else if (x == 1)
		vars->enemy.direction = 0;
	else if (x == -1)
		vars->enemy.direction = 3;
}

static int	ft_is_pos(t_vars *vars, int random)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (random == 0)
		y = 1;
	else if (random == 1)
		y = -1;
	else if (random == 2)
		x = 1;
	else if (random == 3)
		x = -1;
	if (vars->map[vars->enemy.pos_x + x][vars->enemy.pos_y + y] == '1')
		return (0);
	ft_direction_enemy_asset(vars, x, y);
	vars->enemy.pos_x += x;
	vars->enemy.pos_y += y;
	return (1);
}

void	ft_move_enemy(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->move == 150)
	{
		while (!ft_is_pos(vars, rand() % 4) && ++i < 10)
			;
		vars->move = 0;
	}
	vars->move++;
}
