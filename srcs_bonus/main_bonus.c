/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:56:03 by aleferra          #+#    #+#             */
/*   Updated: 2022/02/09 15:29:23 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		printf("Error\n");
		printf("Probleme d'argument\n");
		exit(EXIT_FAILURE);
	}
	vars.map = ft_file_map(&vars, argv[1]);
	ft_is_parse(vars.map, argv[1]);
	vars = ft_get_info(vars, argv[1]);
	ft_open_win(vars);
	exit(EXIT_SUCCESS);
}
