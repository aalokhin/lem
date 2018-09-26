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
		ft_printf("Are you trying to pass a folder, lil fucka?\n");
	else if (input->error == 18)
		ft_printf("You fucking sucka, you provided us with a map that makes it impossible to create path.\n All ants are gonna die now\n");
	else if (input->error == 19)
		ft_printf("Incorrect input, required data is missing. Check if start/end is defined. \n");
	else if (input->error == 20)
		ft_printf("You need to specify the correct integer ANTS number before entering other data\n");
	else if (input->error == 21)
		ft_printf("Not enugh data to proceed\n");
	else if (input->error == 22)
		ft_printf("wrong number of spaces in the line\n");
	else if (input->error == 23)
		ft_printf("wrong number of dashes in the line\n");
	else if (input->error == 24)
		ft_printf("Not enough data to initiate algorithm\n");
}

void			error_message_2(t_input *input)
{
	if (input->error == 11)
		ft_printf("There already is a room with this name\n");
	else if (input->error == 12)
		ft_printf("There already is a room with these coordinates. Are you gonna place two rooms in one spot?\n");
	else if (input->error == 13)
		ft_printf("Unknown type of line, input error\n");
	else if (input->error == 14)
		ft_printf("You cannot add links before start and end are defined\n");
	else if (input->error == 15)
		ft_printf("Room name cannot start with 'L' \n");
	else if (input->error == 16)
		ft_printf("Error of unknown issue\n");
	else
		error_message_3(input);
}

void			error_message(t_input *input)
{
	if (input->error == 1)
		ft_printf("ERROR ON INPUT: incorrect room line, 2d and 3d argument should be cordinates\n");
	else if (input->error == 2)
		ft_printf("ERROR ON INPUT: we already have ants number specified, you cannot have more than 1 \"First Line\"\n");
	else if (input->error == 3)
		ft_printf("You have to set the correct ants number first\n");
	else if (input->error == 4)
		ft_printf("You need to put room after start, not  link\n");
	else if (input->error == 5)
		ft_printf("the link links to non-existing room\n");
	else if (input->error == 6)
		ft_printf("there is no start you stupid shit for brains\n");
	else if (input->error == 7)
		ft_printf("there is no END you stupid shit for brains\n");
	else if (input->error == 8)
		ft_printf("ants nbr can't be below zero, idiot");
	else if (input->error == 9)
		ft_printf("doublestart, dude. stop it now pls");
	else if (input->error == 10)
		ft_printf("double END, dude. stop it now pls");
	else
		error_message_2(input);
}
