/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:21:47 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/24 17:39:41 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_touches(char **map, int i, int j)
{
	int	count;

	count = 0;
	if (j < 3 && map[i][j + 1] == '#')
		count++;
	if (i < 3 && map[i + 1][j] == '#')
		count++;
	if (j > 0 && map[i][j - 1] == '#')
		count++;
	if (i > 0 && map[i - 1][j] == '#')
		count++;
	return (count);
}

void	check_shape(char **map)
{
	int		count;
	int		i;
	int		j;
	int		amount;

	count = 0;
	amount = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '#')
			{
				amount++;
				count += count_touches(map, i, j);
			}
			j++;
		}
		i++;
	}
	if ((count != 6 && count != 8) || amount != 4)
		case_of_error();
}
