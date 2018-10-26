/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:55:32 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/26 14:55:34 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				is_first_line(char *line, t_input *input)
{
	if (is_all_digits(line) && input->ant_nr == -1 && ft_atoi(line) > 0)
		return (1);
	else if (is_all_digits(line) && input->ant_nr == -1 && ft_atoi(line) <= 0)
	{
		input->error = (input->error == 0) ? 8 : input->error;
		return (1);
	}
	else if (is_all_digits(line) && input->ant_nr != -1)
	{
		input->error = (input->error == 0) ? 2 : input->error;
		return (0);
	}
	else
		return (0);
}

void			ft_clean_parse(char **parse)
{
	int i;

	i = 0;
	while (parse[i])
		ft_strdel(&parse[i++]);
	free(parse);
}

int				check_if_r_exists(t_anthill **r, char *line, t_input *input)
{
	char		**parse;
	int			i;
	t_anthill	*q;

	i = 0;
	q = *r;
	parse = ft_strsplit(line, ' ');
	while (q != NULL)
	{
		if (ft_strequ(q->name, parse[0]))
		{
			input->error = (input->error == 0) ? 11 : input->error;
			break ;
		}
		else if (ft_atoi(parse[1]) == q->x &&\
		ft_atoi(parse[2]) == q->y)
		{
			input->error = (input->error == 0) ? 12 : input->error;
			break ;
		}
		q = q->next;
	}
	ft_clean_parse(parse);
	return ((input->error == 0) ? 0 : 1);
}
