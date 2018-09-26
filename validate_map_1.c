/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:57:07 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/26 14:57:10 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_all_digits(char *line)
{
	int		i;

	i = 0;
	if (line[i] == '-' || line[i] == '+')
		i++;
	if (line[i] == '\0')
		return (0);
	while (line[i] != '\0')
	{
		if (!(ft_isdigit(line[i])))
			return (0);
		i++;
	}
	return (1);
}

void		validate_room(char *line, char **parse, t_input *input)
{
	if (is_all_digits(parse[1]) == 0 ||\
	is_all_digits(parse[2]) == 0)
		input->error = 1;
	else if (parse[0][0] == 'L')
		input->error = 15;
	if (input->ant_nr == -1)
		input->error = 3;
	if (count_symbols(line, ' ') != 2)
		input->error = 22;
}

int			is_room(char *line, t_input *input)
{
	char	**parse;
	int		i;

	i = 0;
	parse = ft_strsplit(line, ' ');
	while (parse[i])
		i++;
	if (i != 3)
	{
		ft_clean_parse(parse);
		return (0);
	}
	else
		validate_room(line, parse, input);
	ft_clean_parse(parse);
	return (1);
}
