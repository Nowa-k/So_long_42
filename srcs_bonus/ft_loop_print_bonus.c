/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_print_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:21:03 by aleferra          #+#    #+#             */
/*   Updated: 2022/02/07 18:43:57 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	print_obj(t_vars *vars)
{
	t_compo	*tmp;
	char	*res;

	tmp = vars->pieces;
	while (tmp)
	{
		if (tmp->is == 1)
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgkey,
				(tmp->pos.pos_x * 100), (tmp->pos.pos_y * 100));
		tmp = tmp->next;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgchest,
		(vars->escape.pos_x * 100), (vars->escape.pos_y * 100));
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgperso,
		(vars->perso.pos_x * 100), (vars->perso.pos_y * 100));
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgenemy,
		(vars->enemy.pos_y * 100), (vars->enemy.pos_x * 100));
	res = ft_itoa(vars->nbpas);
	mlx_string_put(vars->mlx, vars->mlx_win, 50, 50, 0xF8F8FF, "Move :");
	mlx_string_put(vars->mlx, vars->mlx_win, 100, 50, 0xF8F8FF, res);
	free(res);
	if ((vars->perso.pos_y == vars->enemy.pos_x)
		&& (vars->perso.pos_x == vars->enemy.pos_y))
		exit(EXIT_FAILURE);
}

static void	ft_get_asset(t_vars *vars)
{
	ft_direction_enemy(vars);
	ft_direction_heros(vars);
	vars->imgbloc = mlx_xpm_file_to_image(vars->mlx,
			"images/sol.xpm", &vars->width, &vars->height);
	vars->imgground = mlx_xpm_file_to_image(vars->mlx,
			"images/muraille.xpm", &vars->width, &vars->height);
	vars->imgchest = mlx_xpm_file_to_image(vars->mlx,
			"images/chest.xpm", &vars->width, &vars->height);
	vars->imgkey = mlx_xpm_file_to_image(vars->mlx,
			"images/key.xpm", &vars->width, &vars->height);
}

static void	print_back_ground(t_vars *vars)
{
	int	line;
	int	col;

	line = -1;
	while (++line < vars->line_map)
	{
		col = -1;
		while (++col < vars->col_map)
		{
			if (vars->map[line][col] == '1')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->imgground, (col * 100), (line * 100));
			else
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->imgbloc, (col * 100), (line * 100));
		}
	}
}

static void	ft_destroy(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->imgbloc);
	mlx_destroy_image(vars->mlx, vars->imgenemy);
	mlx_destroy_image(vars->mlx, vars->imgground);
	mlx_destroy_image(vars->mlx, vars->imgperso);
	mlx_destroy_image(vars->mlx, vars->imgchest);
	mlx_destroy_image(vars->mlx, vars->imgkey);
}

int	ft_loop_print(t_vars *vars)
{
	ft_get_asset(vars);
	ft_move_enemy(vars);
	print_back_ground(vars);
	print_obj(vars);
	ft_destroy(vars);
	return (1);
}
