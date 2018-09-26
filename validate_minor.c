/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_minor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:57:51 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/26 14:57:52 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_ishash(int c)
{
	if (c == 35)
		return (1);
	return (0);
}

int				count_symbols(char *line, int c)
{
	int			i;

	i = 0;
	while (*line != '\0')
	{
		if (*line == c)
			i++;
		line++;
	}
	return (i);
}

int				empty_line(char *line)
{
	if (ft_strequ("\n", line) || ft_strequ("", line))
		return (1);
	return (0);
}

int				is_comment(char *line)
{
	if (ft_ishash(line[0]) &&\
	!(ft_strequ("##end", line)) &&\
	!(ft_strequ("##start", line)))
		return (1);
	else
		return (0);
}

int				found_name(char *new_name, t_anthill **room)
{
	t_anthill *head;

	head = *room;
	while (head)
	{
		if (ft_strequ(new_name, head->name))
			return (1);
		head = head->next;
	}
	return (0);
}
