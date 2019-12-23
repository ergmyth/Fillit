/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:34:54 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/24 17:38:52 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	make_arr(int i, int j, int **arr, char **map)
{
	int		d;
	int		b;
	int		k;

	k = 0;
	d = i;
	while (map[d])
	{
		b = (d != i) ? 0 : j;
		while (map[d][b])
		{
			if (map[d][b] == '#')
			{
				if (!(arr[k] = (int*)malloc(sizeof(int) * 2)))
					case_of_error();
				arr[k][0] = d - i;
				arr[k][1] = b - j;
				k++;
			}
			b++;
		}
		d++;
	}
}

int			**int_array(char **map)
{
	int		i;
	int		j;
	int		**arr;

	if (!(arr = (int**)malloc(sizeof(int*) * 4)))
		case_of_error();
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '#')
			{
				make_arr(i, j, arr, map);
				return (arr);
			}
			j++;
		}
		i++;
	}
	return (0);
}
