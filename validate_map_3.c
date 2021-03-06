/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:57:22 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/26 14:57:24 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_valid_link(char *line, t_input *input, t_anthill **room)
{
	char	**parse;

	parse = ft_strsplit(line, '-');
	if (found_name(parse[0], room) && found_name(parse[1], room))
	{
		ft_clean_parse(parse);
		return (1);
	}
	ft_clean_parse(parse);
	input->error = (input->error == 0) ? 5 : input->error;
	return (0);
}

int			is_link(char *line, t_input *input)
{
	char	**parse;
	int		i;

	parse = ft_strsplit(line, '-');
	i = 0;
	while (parse[i])
		i++;
	if (i == 2)
	{
		if (input->start == -1 || input->end == -1)
			input->error = (input->error == 0) ? 14 : input->error;
		else if (input->start == 1)
			input->error = (input->error == 0) ? 4 : input->error;
		else if (count_symbols(line, '-') != 1)
			input->error = (input->error == 0) ? 23 : input->error;
		ft_clean_parse(parse);
		return (1);
	}
	ft_clean_parse(parse);
	return (0);
}
