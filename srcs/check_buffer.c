/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 10:27:39 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/24 17:40:24 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_buffer(char *buffer)
{
	int		i;
	int		j;

	i = 0;
	while (i < 20)
	{
		j = i + 1;
		if (j % 5 == 0 && buffer[i] != '\n')
			case_of_error();
		if (j % 5 != 0 && buffer[i] != '#' && buffer[i] != '.')
			case_of_error();
		i++;
	}
	if (ft_strlen(buffer) == 21 && buffer[i] != '\n')
		case_of_error();
}
