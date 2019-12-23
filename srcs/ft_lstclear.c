/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:32:33 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/24 18:35:34 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_lstclear(t_tetrm **tetrm, char *buffer)
{
	t_tetrm	*lst1;
	t_tetrm	*lst2;
	int		i;

	lst1 = *tetrm;
	while (lst1)
	{
		lst2 = lst1->next;
		i = 0;
		while (i < 4)
		{
			free(lst1->fig[i]);
			i++;
		}
		free(lst1->fig);
		free(lst1);
		lst1 = lst2;
	}
	free(buffer);
	return (1);
}
