/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:58:16 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/26 14:58:18 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			count_dist(t_anthill **q_head)
{
	int			k;
	t_anthill	*a;
	t_chain		*b;

	if (!q_head || !*q_head)
		return ;
	k = 0;
	a = *q_head;
	b = a->chain;
	while (a)
	{
		k = 0;
		b = a->chain;
		while (b)
		{
			b = b->next;
			k++;
		}
		a->length = k;
		a = a->next;
	}
}

t_lines			*backup_line(char *line)
{
	t_lines		*new;

	if (!(new = (t_lines*)malloc(sizeof(t_lines))))
		return (NULL);
	else
		new->save = ft_strdup(line);
	new->next = NULL;
	return (new);
}

void			add_line_to_list(t_lines **head, char *line)
{
	t_lines		*new;
	t_lines		*last;

	new = backup_line(line);
	if (!head || !new)
		return ;
	last = *head;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}
