/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:58:02 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/26 14:58:04 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			fill_input(t_input *input)
{
	input->read = -1;
	input->error = 0;
	input->ant_nr = -1;
	input->start = -1;
	input->end = -1;
	input->brk = 0;
	input->lines = ft_memalloc(sizeof(t_lines));
}

void			launch_algorithm(t_anthill **room, t_input *input)
{
	t_anthill	*que;

	que = NULL;
	if (verify_input(*room, input) == 0)
		error_message(input);
	else
	{
		que = create_queue(&(*room), input);
		if (!que)
		{
			if (input->error == 0)
				input->error = 18;
			error_message(input);
			return ;
		}
		print_out_input(input);
		if (is_one_way(que))
			output_one_step(que, input);
		else
			output_function(que, input);
	}
	delete_all_que(&que);
}

int				main(void)
{
	t_input		input;
	char		*line;
	t_anthill	*room;

	room = NULL;
	fill_input(&input);
	while (input.read != 0)
	{
		if (input.brk || input.error != 0 ||\
		(input.read = get_next_line(0, &line)) == 0)
			break ;
		ft_check_line(&input, &line, &room);
		if (!input.brk && !input.error && line)
			add_line_to_list(&input.lines, line);
		ft_strdel(&line);
	}
	launch_algorithm(&room, &input);
	delete_rooms_list(&room);
	delete_lines_list(&input.lines);
	return (0);
}
