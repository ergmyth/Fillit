/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_here.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 10:01:13 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/24 18:39:28 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_and_add(char *buffer, t_tetrm **list, int count)
{
	t_tetrm *elem;
	char	**map;

	check_buffer(buffer);
	map = buffer_to_map(buffer);
	check_shape(map);
	if (!list)
	{
		elem = new_tetrm(65 + count, int_array(map));
		list = &elem;
	}
	else
	{
		elem = new_tetrm(65 + count, int_array(map));
		ft_append(list, elem);
	}
	ft_freep(map, 6);
}

void	read_here(int fd)
{
	int		buff_size;
	char	*buffer;
	int		c;
	t_tetrm *list;

	buff_size = 21;
	if (!(buffer = (char*)malloc(buff_size + 1)))
		case_of_error();
	ft_bzero(buffer, buff_size + 1);
	c = 0;
	while (1)
	{
		ft_strclr(buffer);
		if (read(fd, buffer, buff_size) == 0)
			break ;
		buff_size = ft_strlen(buffer);
		if (buff_size != 21 && buff_size != 20)
			case_of_error();
		check_and_add(buffer, &list, c);
		if (c++ && buff_size == 20)
			break ;
	}
	if ((c == 0 || c > 26 || buff_size == 21) && ft_lstclear(&list, buffer))
		case_of_error();
	fillit(list, c, buffer);
}
