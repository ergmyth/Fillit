/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_to_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:05:00 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/24 17:41:25 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	fill_last_string(char **map)
{
	int	i;

	i = 0;
	if (!(map[4] = (char*)malloc(5)))
		case_of_error();
	while (i < 4)
	{
		map[4][i] = '\0';
		i++;
	}
}

char		**buffer_to_map(char *buffer)
{
	char	**map;
	int		i;
	int		j;

	if (!(map = (char**)malloc(sizeof(char*) * 6)))
		case_of_error();
	i = 0;
	map[5] = 0;
	while (i < 4)
	{
		if (!(map[i] = (char*)malloc(5)))
			case_of_error();
		j = 0;
		while (j < 4)
		{
			map[i][j] = *buffer;
			buffer++;
			j++;
		}
		map[i][4] = '\0';
		buffer++;
		i++;
	}
	fill_last_string(map);
	return (map);
}
