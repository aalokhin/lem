/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:08:18 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/26 16:08:19 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			delete_chain_in_q_element(t_chain *head)
{
	t_chain *next;

	if (!head)
		return ;
	while (head != NULL)
	{
		next = (head)->next;
		free(head);
		head = next;
	}
}

void			delete_rooms_list(t_anthill **head)
{
	t_anthill	*next;

	if (!head)
		return ;
	while (*head != NULL)
	{
		next = (*head)->next;
		ft_strdel(&(*head)->name);
		delete_all_chain(*head);
		(*head) = next;
	}
}

void			delete_lines_list(t_lines **head)
{
	t_lines		*next;

	if (!head || !*head)
		return ;
	while ((*head) != NULL)
	{
		next = (*head)->next;
		ft_strdel(&(*head)->save);
		free((*head));
		(*head) = next;
	}
}

void			delete_unneeded(t_anthill **head)
{
	t_anthill	*prev;
	t_anthill	*tmp;

	tmp = *head;
	prev = tmp;
	while (tmp != NULL && tmp->del == 1)
	{
		*head = tmp->next;
		delete_all_chain(tmp);
		tmp = *head;
	}
	while (tmp != NULL)
	{
		while (tmp != NULL && tmp->del != 1)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp == NULL)
			return ;
		prev->next = tmp->next;
		delete_all_chain(tmp);
		tmp = prev->next;
	}
}
