/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:57:42 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/26 14:57:44 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				verify_input(t_anthill *room, t_input *input)
{
	if (!find_start(room, input) ||\
	!find_end(room, input))
	{
		if (input->error == 0)
			input->error = 24;
		return (0);
	}
	if (input->start == -1 || input->end == -1 || input->ant_nr <= 0)
	{
		if (input->error == 0)
		{
			if (input->start == -1)
				input->error = 6;
			else if (input->end == -1)
				input->error = 7;
		}
		return (0);
	}
	return (1);
}

void			ft_check_line2(t_input *input, char **line, t_anthill **room)
{
	if (ft_is_start(*line, input) && input->end != 1)
		input->start = 1;
	else if (is_room(*line, input))
	{
		if (!(check_if_r_exists(room, *line, input)))
			add_room_to_list(room, *line, input);
	}
	else if (is_link(*line, input))
	{
		if (is_valid_link(*line, input, room))
			add_link_to_list(room, *line, input);
	}
	else if (ft_is_end(*line, input))
		input->error = 26;
	else if (ft_is_start(*line, input))
		input->error = 26;
	else
	{
		input->brk = 1;
		return ;
	}
}

void			ft_check_line(t_input *input, char **line, t_anthill **room)
{
	if (!line || !*line)
		input->error = (input->error == 0) ? 17 : input->error;
	else if (input->ant_nr == -1 && !is_comment(*line) &&\
	!is_first_line(*line, input))
		input->error = (input->error == 0) ? 20 : input->error;
	else if (empty_line(*line))
	{
		input->brk = 1;
		return ;
	}
	else if (is_comment(*line))
		return ;
	else if (is_first_line(*line, input))
		input->ant_nr = ft_atoi(*line);
	else if (ft_is_end(*line, input) && input->start != 1)
		input->end = 1;
	else
		ft_check_line2(input, line, room);
}
