/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tetrm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:46:50 by ifran             #+#    #+#             */
/*   Updated: 2019/09/25 19:05:45 by ifran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrm		*new_tetrm(char count, int **fig)
{
	t_tetrm	*new;

	new = (t_tetrm*)malloc(sizeof(t_tetrm));
	if (!new)
		case_of_error();
	new->count = count;
	new->s = 0;
	new->fig = fig;
	new->next = NULL;
	return (new);
}
