/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:11:04 by aleferra          #+#    #+#             */
/*   Updated: 2022/02/16 11:22:08 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_nb_line(char *str)
{
	int		fd;
	int		nbline;
	char	*res;

	nbline = 0;
	fd = open(str, O_RDONLY);
	res = get_next_line(fd);
	while (res)
	{
		nbline++;
		free(res);
		res = get_next_line(fd);
	}
	free(res);
	close(fd);
	return (nbline);
}

int	ft_nb_col(char **map)
{
	int	index;

	index = -1;
	while (map[0][++index])
		;
	return (index - 1);
}

int	ft_exit(t_vars **vars)
{
	(void)vars;
	exit(EXIT_SUCCESS);
	return (1);
}

t_compo	*ft_add_back(t_compo **chaine, t_compo *new)
{
	t_compo		*tmp;

	if (!new)
		return (NULL);
	if (!*chaine)
	{
		*chaine = new;
	}
	else
	{
		tmp = *chaine;
		while (tmp->next)
			tmp = tmp->next;
		new->next = NULL;
		tmp->next = new;
	}
	return (*chaine);
}

t_compo	*ft_add_new_comp(int x, int y)
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
