/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:38:08 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/26 15:38:09 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_out_input(t_input *input)
{
	t_lines		*print;

	if (!(input->lines))
		return ;
	print = input->lines;
	while (print)
	{
		if (print->save)
			ft_printf("%s\n", print->save);
		print = print->next;
	}
	ft_printf("\n");
}

void			error_message_3(t_input *input)
{
	if (input->error == 17)
		ft_printf("Are you trying to pass something that doesn't exist?\n");
	else if (input->error == 18)
	{
		ft_printf("The map you provided us with makes it impossible to create");
		ft_printf(" path. All ants are gonna die inside the maze now.\n");
	}
	else if (input->error == 19)
	{
		ft_printf("Incorrect input, required data is missing. ");
		ft_printf("Check if start/end is defined. \n");
	}
	else if (input->error == 20)
		ft_printf("A valid integer number of ants is needed to proceed.\n");
	else if (input->error == 21)
		ft_printf("Not enough data to proceed.\n");
	else if (input->error == 22)
		ft_printf("Wrong number of spaces in the line.\n");
	else if (input->error == 23)
		ft_printf("Wrong number of dashes in the line.\n");
	else if (input->error == 24)
		ft_printf("Not enough data to initiate algorithm.\n");
	else if (input->error == 26)
		ft_printf("You need to provide data in proper order.\n");
}

void			error_message_2(t_input *input)
{
	if (input->error == 9)
		ft_printf("Double start, dude. Stop it now please.\n");
	else if (input->error == 10)
		ft_printf("Double end, dude. Stop it now please.\n");
	else if (input->error == 11)
		ft_printf("There already is a room with this name.\n");
	else if (input->error == 12)
	{
		ft_printf("There already is a room with these coordinates. ");
		ft_printf("How are you gonna place two rooms in one spot?\n");
	}
	else if (input->error == 13)
		ft_printf("Unknown type of line, input error.\n");
	else if (input->error == 14)
		ft_printf("You cannot add links before start and end are defined.\n");
	else if (input->error == 15)
		ft_printf("Room name cannot start with 'L'.\n");
	else if (input->error == 16)
		ft_printf("Error of unknown issue.\n");
	else
		error_message_3(input);
}

void			error_message(t_input *input)
{
	if (input->error == 1)
	{
		ft_printf("Looks like incorrect room line. ");
		ft_printf("Second and third argument should be cordinates.\n");
	}
	else if (input->error == 2)
		ft_printf("We already have ants. We don't need any other numbers.\n");
	else if (input->error == 3)
		ft_printf("You have to set the correct ants number first.\n");
	else if (input->error == 4)
		ft_printf("You need to put your room line after start, not link.\n");
	else if (input->error == 5)
	{
		ft_printf("Either the link links to non-existing room ");
		ft_printf("or the line is incorrect.\n");
	}
	else if (input->error == 6)
		ft_printf("There is no start room to place ants in.\n");
	else if (input->error == 7)
		ft_printf("There is no end. Where do you think your ants are going?\n");
	else if (input->error == 8)
		ft_printf("Ants nbr can't go below zero or the line is incorrect.\n");
	else
		error_message_2(input);
}
