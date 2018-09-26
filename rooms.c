/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:46:17 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/26 15:46:19 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_anthill			*parse_room(char *line, t_input *input)
{
	t_anthill		*new_room;
	char			**parse;

	parse = ft_strsplit(line, ' ');
	new_room = ft_memalloc(sizeof(t_anthill));
	new_room->x = ft_atoi(parse[1]);
	new_room->y = ft_atoi(parse[2]);
	if (line)
		new_room->name = ft_strdup(parse[0]);
	else
		new_room->name = NULL;
	ft_clean_parse(parse);
	if (input->start == 1)
	{
		new_room->is_start = 1;
		input->start = 0;
	}
	if (input->end == 1)
	{
		new_room->is_end = 1;
		input->end = 0;
	}
	return (new_room);
}

void				add_room_to_list(t_anthill **head, char *line, t_input *i)
{
	t_anthill		*new;
	t_anthill		*last;

	new = parse_room(line, i);
	if (!head || !new)
		return ;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}
