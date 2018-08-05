#include "lem_in.h"


int				ft_ishash(int c)
{
	if (!(c == 35))
		return (0);
	return (1);
}


int 			is_first_line(char	*line) //is forst line
{
	int 		i;

	i = 0;
	while (line[i])
	{
		if (!(ft_isdigit(line[i])))
			return (0);
		i++;
	}
	return (1);
}

int 			is_comment(char	*line)
{
	if (ft_ishash(line[0]) && !(ft_ishash(line[1])))//is commment
		return(1)
	else
		return (0);
}

int 		is_room(char *line)//if the room is correct
{
	int 	count;
	int 	i;
	int 	error;

	count = 0;
	i = 0;
	error = 0;
	while(line && line[i] && line[i] != ' ')
		i++;
	while(line && line[i])
	{
		if (line[i] == ' ' && line[i + 1] && ft_isdigit(line[i + 1])) 
			count++;
		if (count > 2)
			error++;
		if (line[i] != ' ' && !ft_isdigit(line[i]))
			error++;
		i++;
	}
	if (error)
		return (0);
	return (1);

}

int 		is_link(char *line)
{
	int 	i;
	int 	count;

	i = 0;
	count = 0;
	while(line && line[i])
	{
		if (line[i] == '-')
			count++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int 	correct_link(char *line)
{
	
}

int			ft_check_map_2(t_input *input)// shoudl return 1 if ok and 0 if error
{
	char		*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (is_room(line))
			insert_room(&line)
		ft_strdel(&line);
	}
}

int			ft_check_map_1(t_input **input)// shoudl return 1 if ok and 0 if error
{
	char		*line;
	int 		i;

	line = NULL;
	while ((*input)->ant_nr == 0)
	{
		get_next_line(0, &line);
		if (is_comment(line))
		{
			ft_strdel(line);
			continue ;
		}
		else if(is_first_line(line))
		{
			ft_strdel(line);
			(*input)->ant_nr = ft_atoi(line);
		}
		else
		{
			ft_strdel(line);
			(*input)->error++;
			break ;		
		}
	}
	if ((*input)->error > 0)
		return(0);
	return (1);

}






int				main(void)
{
	char		*line;
	t_input		*input;

	ft_check_map_1(&input);
	while (read)
	{
		read = get_next_line(0, &line);

		free(line);
	}

}





