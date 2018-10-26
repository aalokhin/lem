/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:48:13 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/26 15:48:14 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					is_empty(t_anthill *que)
{
	t_anthill		*q;
	t_chain			*way;

	q = que;
	way = q->chain->next;
	while (q != NULL)
	{
		way = q->chain->next;
		while (way != NULL)
		{
			if (way->id != 0)
				return (1);
			way = way->next;
		}
		q = q->next;
	}
	return (0);
}

void				arrange_ants2(t_chain *way_st, t_input *input, int *index)
{
	t_chain			*way;

	if (!way_st)
		return ;
	way = way_st;
	while (way->next)
		way = way->next;
	while (way->start != 1)
	{
		if (way->prev->start == 1)
		{
			if (input->ant_nr >= *index)
			{
				way->id = *index;
			}
			else
				way->id = 0;
		}
		else if (way->prev->start != 1)
			way->id = way->prev->id;
		way = way->prev;
	}
}

void				arrange_ants(t_anthill *que, t_input *input, int *index)
{
	t_anthill		*q;
	t_chain			*way;

	q = que;
	while (q)
	{
		way = q->chain->next;
		arrange_ants2(way, input, index);
		(*index)++;
		q = q->next;
	}
}

void				print_ants(t_anthill *que)
{
	t_anthill		*q;
	t_chain			*way;
	int				flag;

	flag = 0;
	q = que;
	while (q)
	{
		way = q->chain->next;
		while (way->next)
			way = way->next;
		while (way->prev)
		{
			if (way->id != 0)
			{
				if (flag > 0)
					ft_printf(" ");
				ft_printf("L%d-%s", way->id, way->nombre);
				flag = 1;
			}
			way = way->prev;
		}
		q = q->next;
	}
	ft_printf("\n");
}

void				output_function(t_anthill *que, t_input *input)
{
	int				empty;
	t_anthill		*q;
	int				index;

	empty = 1;
	if (!que)
		return ;
	q = que;
	index = 1;
	while (empty != 0)
	{
		q = que;
		arrange_ants(que, input, &index);
		empty = is_empty(que);
		if (empty == 0)
			break ;
		q = que;
		print_ants(q);
	}
}
