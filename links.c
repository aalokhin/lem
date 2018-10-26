/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:59:23 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/26 15:59:25 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				add_chain(t_anthill *r1, t_anthill *r2)
{
	t_chain			*new_link;

	if (!r1 || !r2)
		return ;
	if (!(new_link = (t_chain*)malloc(sizeof(t_chain))))
		return ;
	new_link->next = r1->chain;
	r1->chain = new_link;
	new_link->ngbr = r2;
	if (!(new_link = (t_chain*)malloc(sizeof(t_chain))))
		return ;
	new_link->next = r2->chain;
	r2->chain = new_link;
	new_link->ngbr = r1;
}

t_anthill			*search_room(t_anthill **head, char *name1, t_input *input)
{
	t_anthill		*search;

	search = *head;
	while (search != NULL)
	{
		if (ft_strequ(search->name, name1))
			return (search);
		search = search->next;
	}
	if (input->error == 0)
		input->error = 5;
	return (NULL);
}

void				add_link_to_list(t_anthill **head, char *l, t_input *input)
{
	char			**parse;
	t_anthill		*tmp;
	t_anthill		*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	parse = ft_strsplit(l, '-');
	if (!(tmp = search_room(head, parse[0], input)))
		return ;
	if (!(tmp2 = search_room(head, parse[1], input)))
		return ;
	ft_clean_parse(parse);
	add_chain(tmp, tmp2);
}

void				add_copy_chain(t_chain **head, t_anthill *room)
{
	t_chain			*new;
	t_chain			*last;

	if (!head)
		return ;
	new = ft_memalloc(sizeof(t_chain));
	new->ngbr = room;
	new->next = NULL;
	new->nombre = room->name;
	new->id = 0;
	new->start = room->is_start;
	new->end = room->is_end;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return ;
	}
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;
}
