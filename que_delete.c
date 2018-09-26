/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   que_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:06:50 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/26 15:06:52 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			delete_all_chain(t_anthill *element)
{
	t_chain		*down;
	t_chain		*temp;

	down = element->chain;
	while (down)
	{
		temp = down;
		temp->ngbr = NULL;
		temp->nombre = NULL;
		down = down->next;
		free(temp);
	}
	element->name = NULL;
	free(element);
}

void			delete_all_que(t_anthill **que)
{
	t_anthill	*q;

	while (*que != NULL)
	{
		q = (*que)->next;
		delete_all_chain(*que);
		(*que) = q;
	}
}

void			delete_from_q(t_anthill **head, t_anthill *del)
{
	t_anthill	*temp;
	t_anthill	*prev;

	temp = *head;
	prev = temp;
	if (temp != NULL && temp == del)
	{
		*head = temp->next;
		delete_chain_in_q_element(temp->chain);
		free(temp);
		return ;
	}
	while (temp != NULL && temp != del)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	delete_chain_in_q_element(temp->chain);
	free(temp);
}

void			clean_q(t_anthill *end, t_anthill **q_head)
{
	t_anthill	*x;
	t_anthill	*x1;
	t_chain		*b;

	x = *q_head;
	b = x->chain;
	x1 = NULL;
	while (x)
	{
		b = x->chain;
		while (b->next != NULL)
			b = b->next;
		if (b->ngbr != end)
		{
			x1 = x;
			delete_from_q(q_head, x1);
		}
		x = x->next;
	}
}
