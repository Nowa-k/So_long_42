/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction_asset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:44:11 by aleferra          #+#    #+#             */
/*   Updated: 2022/02/07 18:44:42 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_direction_enemy(t_vars *vars)
{
	if (vars->enemy.direction == 0)
		vars->imgenemy = mlx_xpm_file_to_image(vars->mlx,
				"images/enemyface.xpm", &vars->width, &vars->height);
	else if (vars->enemy.direction == 1)
		vars->imgenemy = mlx_xpm_file_to_image(vars->mlx,
				"images/enemyright.xpm", &vars->width, &vars->height);
	else if (vars->enemy.direction == 2)
		vars->imgenemy = mlx_xpm_file_to_image(vars->mlx,
				"images/enemyleft.xpm", &vars->width, &vars->height);
	else if (vars->enemy.direction == 3)
		vars->imgenemy = mlx_xpm_file_to_image(vars->mlx,
				"images/enemyback.xpm", &vars->width, &vars->height);
}

void	ft_direction_heros(t_vars *vars)
{
	if (vars->perso.direction == 0)
		vars->imgperso = mlx_xpm_file_to_image(vars->mlx,
				"images/herosface.xpm", &vars->width, &vars->height);
	else if (vars->perso.direction == 1)
		vars->imgperso = mlx_xpm_file_to_image(vars->mlx,
				"images/herosright.xpm", &vars->width, &vars->height);
	else if (vars->perso.direction == 2)
		vars->imgperso = mlx_xpm_file_to_image(vars->mlx,
				"images/herosleft.xpm", &vars->width, &vars->height);
	else if (vars->perso.direction == 3)
		vars->imgperso = mlx_xpm_file_to_image(vars->mlx,
				"images/herosback.xpm", &vars->width, &vars->height);
}
