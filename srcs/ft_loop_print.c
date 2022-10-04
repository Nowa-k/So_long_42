/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:21:03 by aleferra          #+#    #+#             */
/*   Updated: 2022/02/07 17:03:20 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	print_obj(t_vars *vars)
{
	t_compo	*tmp;

	tmp = vars->pieces;
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgchest,
		(vars->escape.pos_x * 100), (vars->escape.pos_y * 100));
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgperso,
		(vars->perso.pos_x * 100), (vars->perso.pos_y * 100));
	while (tmp)
	{
		if (tmp->is == 1)
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->imgkey,
				(tmp->pos.pos_x * 100), (tmp->pos.pos_y * 100));
		tmp = tmp->next;
	}
}

static void	ft_get_asset(t_vars *vars)
{
	vars->imgbloc = mlx_xpm_file_to_image(vars->mlx,
			"images/sol.xpm", &vars->width, &vars->height);
	vars->imgenemy = mlx_xpm_file_to_image(vars->mlx,
			"images/persoface.xpm", &vars->width, &vars->height);
	vars->imgground = mlx_xpm_file_to_image(vars->mlx,
			"images/muraille.xpm", &vars->width, &vars->height);
	vars->imgperso = mlx_xpm_file_to_image(vars->mlx,
			"images/dino.xpm", &vars->width, &vars->height);
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
	print_back_ground(vars);
	print_obj(vars);
	ft_destroy(vars);
	return (1);
}
