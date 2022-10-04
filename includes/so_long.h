/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:29:47 by aleferra          #+#    #+#             */
/*   Updated: 2022/02/16 10:58:59 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//Header
# include "../mlx/mlx.h"
# include "get_next_line.h"

//Lib
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define KEY_ESC 53
# define KEY_FRONT 13
# define KEY_BACK 1
# define KEY_RIGHT 2
# define KEY_LEFT 0
# define KEY_CLOSE 17

typedef struct s_comp
{
	int	perso;
	int	comp;
	int	sortie;
}				t_comp;

typedef struct s_pos
{
	int	pos_x;
	int	pos_y;
}				t_pos;

typedef struct s_compo
{
	t_pos			pos;
	int				is;
	struct s_compo	*next;
}				t_compo;

typedef struct s_vars
{
	void		*img;
	void		*imgperso;
	void		*imgbloc;
	void		*imgground;
	void		*imgchest;
	void		*imgkey;
	void		*imgenemy;
	void		*mlx;
	void		*mlx_win;
	int			line_map;
	int			col_map;
	int			height;
	int			width;
	char		**map;
	t_pos		perso;
	t_pos		escape;
	t_pos		enemy;
	t_compo		*pieces;
	int			nbpas;
	int			count;
	int			nbkey;
}				t_vars;

//get_info
t_vars	ft_get_info(t_vars vars, char *str);

//utils parse
int		ft_first_last_col(char **map, int maxline);
int		ft_first_last_line(char **map, int line);
int		ft_fd_is_invalid(char *str);

//utils 
int		ft_nb_line(char *str);
int		ft_nb_col(char **map);
int		ft_exit(t_vars **vars);
t_compo	*ft_add_back(t_compo **chaine, t_compo *new);
void	ft_putstr_fd(char *s, int fd);

//parse
int		ft_is_parse(char **map, char *str);

//file map
char	**ft_file_map(t_vars *vars, char *str);

//key_hook
int		ft_key_hook(int key_code, t_vars *vars);

//loop_print
int		ft_loop_print(t_vars *vars);
void	ft_get_image(t_vars *vars);

//open win
void	ft_open_win(t_vars vars);

//itoa
char	*ft_itoa(int n);

#endif
