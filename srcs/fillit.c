/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:50:01 by ifran             #+#    #+#             */
/*   Updated: 2019/09/24 18:34:52 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**matrix(int s)
{
	char	**matrix;
	int		i;
	int		j;

	i = 0;
	if (!(matrix = (char **)malloc(sizeof(char *) * (s))))
		case_of_error();
	while (i < s)
	{
		j = 0;
		if (!(matrix[i] = (char *)malloc(sizeof(char) * (s + 1))))
			case_of_error();
		while (j < s)
		{
			matrix[i][j] = '.';
			++j;
		}
		matrix[i][j] = '\0';
		++i;
	}
	return (matrix);
}

void			fillit(t_tetrm *tetrm, int count, char *buffer)
{
	int		s;
	int		i;
	char	**mat;

	i = 0;
	s = around_sqrt(count * 4);
	while (1)
	{
		mat = matrix(s);
		if (check_size(tetrm, mat, s, count))
			break ;
		ft_freep(mat, s);
		++s;
	}
	while (i < s)
		ft_putendl(mat[i++]);
	ft_freep(mat, s);
	ft_lstclear(&tetrm, buffer);
}
