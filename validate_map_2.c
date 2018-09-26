/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:57:15 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/26 14:57:16 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					ft_is_start(char *line, t_input *input)
{
	if (ft_strequ("##start", line))
	{
		if (input->start != -1)
			input->error = 9;
		return (1);
	}
	return (0);
}

int					ft_is_end(char *line, t_input *input)
{
	if (ft_strequ("##end", line))
	{
		if (input->end != -1)
		{
			input->error = 10;
		}
		return (1);
	}
	return (0);
}

t_anthill			*find_start(t_anthill *room, t_input *input)
{
	t_anthill		*tmp;

	tmp = room;
	while (tmp != NULL && tmp->is_start != 1)
		tmp = tmp->next;
	if (!tmp)
	{
		input->error = 6;
		return (NULL);
	}
	if (tmp->is_start == 1)
	{
		tmp->visited = 1;
	}
	return (tmp);
}

t_anthill			*find_end(t_anthill *room, t_input *input)
{
	t_anthill		*tmp;

	tmp = room;
	while (tmp != NULL && tmp->is_end != 1)
		tmp = tmp->next;
	if (!tmp)
	{
		input->error = 7;
		return (NULL);
	}
	return (tmp);
}
