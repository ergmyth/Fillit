/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:45:23 by ifran             #+#    #+#             */
/*   Updated: 2019/09/25 19:03:45 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_tetrm(t_tetrm *tetrm, char **mat, int i, int j)
{
	int h;
	int fig_i;
	int fig_j;

	h = 0;
	while (h < 4)
	{
		fig_i = (tetrm->fig)[h][0];
		fig_j = (tetrm->fig)[h][1];
		if (((i + fig_i >= tetrm->s) || (j + fig_j >= tetrm->s)) ||\
				((i + fig_i < 0) || (j + fig_j < 0)) ||\
			(mat[i + fig_i][j + fig_j]) != '.')
			return (0);
		++h;
	}
	return (1);
}

static	void	push_tetrm(t_tetrm *tetrm, char **mat, int i, int j)
{
	char	c;
	int		h;
	int		fig_i;
	int		fig_j;

	h = 0;
	c = tetrm->count;
	while (h < 4)
	{
		fig_i = tetrm->fig[h][0];
		fig_j = tetrm->fig[h][1];
		mat[i + fig_i][j + fig_j] = c;
		++h;
	}
}

static void		tetrm_del(t_tetrm *tetrm, char **mat, int i, int j)
{
	int h;
	int fig_i;
	int fig_j;

	h = 0;
	while (h < 4)
	{
		fig_i = tetrm->fig[h][0];
		fig_j = tetrm->fig[h][1];
		mat[i + fig_i][j + fig_j] = '.';
		++h;
	}
}

int				check_size(t_tetrm *tetrm, char **mat, int s, int count)
{
	int i;
	int j;

	tetrm->s = s;
	i = 0;
	while (i < s)
	{
		j = 0;
		while (j < s)
		{
			if (check_tetrm(tetrm, mat, i, j))
			{
				push_tetrm(tetrm, mat, i, j);
				if (tetrm->count == 'A' + (count - 1))
					return (1);
				if (check_size(tetrm->next, mat, s, count))
					return (1);
				tetrm_del(tetrm, mat, i, j);
			}
			++j;
		}
		++i;
	}
	return (0);
}
