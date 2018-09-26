/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_for_one_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:53:47 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/26 15:53:48 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				is_one_way(t_anthill *que)
{
	t_anthill	*q;
	t_chain		*way;

	if (!que)
		return (1);
	q = que;
	way = que->chain->next;
	while (q)
	{
		if (q->length == 2)
			break ;
		q = q->next;
	}
	if (q == NULL)
		return (0);
	q = que;
	while (q)
	{
		if (q->length != 2)
			q->del = 1;
		q = q->next;
	}
	delete_unneeded(&que);
	return (1);
}

void			output_one_step(t_anthill *que, t_input *input)
{
	int			id;
	t_chain		*way;
	t_anthill	*q;

	id = 1;
	q = que;
	way = que->chain->next;
	while (way->ngbr->is_end != 1)
		way = way->next;
	while (id <= input->ant_nr)
	{
		ft_printf("L%d-%s\n", id, way->nombre);
		id++;
	}
}
