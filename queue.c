/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:58:30 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/26 14:58:33 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				not_taken(t_anthill *room)
{
	t_chain		*iter;

	if (!room || !room->chain)
		return (0);
	iter = room->chain;
	while (iter)
	{
		if (iter->start != 1 &&\
		iter->end != 1 && iter->ngbr->taken > 0)
			return (0);
		iter = iter->next;
	}
	return (1);
}

void			mark_taken(t_anthill *room, int mark)
{
	t_chain		*iter;

	if (!room || !room->chain)
		return ;
	iter = room->chain;
	while (iter)
	{
		iter->ngbr->taken = mark;
		iter = iter->next;
	}
}

void			mark_que(t_anthill **head, t_anthill *cur)
{
	t_anthill	*tmp;
	t_anthill	*last;

	if (!head || !*head || !cur)
		return ;
	last = *head;
	while (last)
	{
		last->del = 0;
		mark_taken(last, 0);
		last = last->next;
	}
	tmp = cur;
	mark_taken(tmp, 1);
	last = *head;
	while (last)
	{
		if (not_taken(last) == 0)
			last->del = (last != tmp) ? 1 : last->del;
		else if (not_taken(last) == 1)
			mark_taken(last, 1);
		last = last->next;
	}
}

void			cycle_q(t_anthill **que)
{
	t_chain		*down;
	t_chain		*links;
	t_anthill	*q;

	q = *que;
	while (q != NULL)
	{
		down = q->chain;
		while (down->next != NULL)
			down = down->next;
		links = down->ngbr->chain;
		while (links != NULL)
		{
			if (links->ngbr->visited == 0)
				anthill_push_back(&(*que), create_next_step(q, links->ngbr));
			links = links->next;
			if (down->end == 1)
				break ;
			if (down->end != 1)
				down->ngbr->visited++;
		}
		q = q->next;
	}
}

t_anthill		*create_queue(t_anthill **room, t_input *input)
{
	t_anthill	*que;

	que = NULL;
	anthill_push_back(&que, create_head(find_start((*room), input)));
	cycle_q(&que);
	clean_q(find_end(*room, input), &que);
	count_dist(&que);
	mark_que(&que, que);
	delete_unneeded(&que);
	return (que);
}
