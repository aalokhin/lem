#include "lem_in.h"



t_room		*create_room(char *line)
{
	t_room 	*head;
	int 	i;

	i = 0;
	if (!(head = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	else
	{
		while (line[i] && line[i] != ' ')
			i++;
		head->name = ft_strnew(i);
		ft_strncpy(head->name, line, i);
		head->x = ft_atoi(&line[i]);
		i++;
		head->y = ft_atoi(&line[i]);
	}
	head->next = NULL;
	return (head);
}

void		add_room(t_r **head)
{
	t_room 	*new;
	t_room 	*last;

	new = create_room(line);
	if (!new || !head)
		return ;
	last = *head;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}



void		delete_list(t_room *head)
{
	t_room *next;

	if (!head)
		return ;
	while (head != NULL)
	{
		next = head->next;
		head->x = 0;
		head->y = 0;
		ft_strdel(&(head->name));
		free(head);
		head = next;
	}
}
