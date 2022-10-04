/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleferra <aleferra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:05:53 by aleferra          #+#    #+#             */
/*   Updated: 2022/02/09 13:55:31 by aleferra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif 

// Utils
size_t	ft_strlen(char *s1);
char	*ft_substr(char *s1, int start, int end);
int		ft_strchr(char *s1, int c);
char	*ft_strjoin(char *s1, char *s2);

// Get_next_line
char	*ft_reader(int fd);
char	*ft_joinbuff(char *buff, int fd);
char	*ft_majbuff(char *buff, char *line);
char	*get_next_line(int fd);

#endif