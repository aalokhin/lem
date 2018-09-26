/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_help_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:55:53 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/26 15:55:59 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				chain_push_back(t_chain **head, t_chain *new)
{
	t_chain			*last;

	last = *head;
	if (!head || !head)
		return ;
	if (!(*head))
	{
		*head = new;
		return ;
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = new;
}

void				anthill_push_back(t_anthill **head, t_anthill *new)
{
	t_anthill		*last;

	if (!head || !new)
		return ;
	if (!(*head))
	{
		*head = new;
		return ;
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = new;
}

t_chain				*create_node(t_anthill *room)
{
	t_chain		*new;

	new = ft_memalloc(sizeof(t_chain));
	new->next = NULL;
	new->ngbr = room;
	return (new);
}

t_anthill			*create_next_step(t_anthill *predecessor, t_anthill *room)
{
	t_anthill		*new;
	t_chain			*iter;

	if (!predecessor)
		return (NULL);
	new = ft_memalloc(sizeof(t_anthill));
	if (!predecessor->name)
		predecessor->name = NULL;
	else
		new->name = predecessor->name;
	iter = predecessor->chain;
	while (iter)
	{
		add_copy_chain(&(new->chain), iter->ngbr);
		iter = iter->next;
	}
	add_copy_chain(&(new->chain), room);
	return (new);
}

t_anthill			*create_head(t_anthill *room)
{
	t_anthill		*new;

	new = ft_memalloc(sizeof(t_anthill));
	new->name = room->name;
	add_copy_chain(&(new->chain), room);
	return (new);
}
