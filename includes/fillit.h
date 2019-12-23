/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:12:52 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/25 19:01:27 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"

typedef struct		s_tetrm
{
	char			count;
	int				**fig;
	int				s;
	struct s_tetrm	*next;
}					t_tetrm;

void				case_of_error(void);
void				read_here(int fd);
void				check_buffer(char *buffer);
char				**buffer_to_map(char *buffer);
void				check_shape(char **map);
int					**int_array(char **map);
int					ft_lstclear(t_tetrm **tetrm, char *buffer);
void				ft_append(t_tetrm **alst, t_tetrm *new);
t_tetrm				*new_tetrm(char count, int **fig);
int					check_size(t_tetrm *tetrm, char **mat, int s, int count);
void				fillit(t_tetrm *tetrm, int count, char *buffer);

#endif
