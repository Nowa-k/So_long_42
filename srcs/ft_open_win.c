/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:09:14 by aleferra          #+#    #+#             */
/*   Updated: 2022/02/07 17:03:37 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_open_win(t_vars vars)
{
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, vars.col_map * 100,
			vars.line_map * 100, "SO_LONG");
	mlx_key_hook(vars.mlx_win, ft_key_hook, &vars);
	mlx_loop_hook(vars.mlx, ft_loop_print, &vars);
	mlx_hook(vars.mlx_win, 17, 0, ft_exit, &vars);
	mlx_loop(vars.mlx);
}
