/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 08:36:37 by aalokhin          #+#    #+#             */
/*   Updated: 2018/09/27 08:36:39 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/includes/libft.h"
# include <fcntl.h>

typedef struct			s_input
{
	int					read;
	int					error;
	int					ant_nr;
	int					start;
	int					end;
	int					brk;
	struct s_lines		*lines;

}						t_input;

typedef struct			s_lines
{
	char				*save;
	struct s_lines		*next;
}						t_lines;

typedef struct			s_anthill
{
	char				*name;
	int					x;
	int					y;
	int					is_start;
	int					is_end;
	int					visited;
	int					del;
	int					taken;
	int					way;
	int					length;
	int					capacity;
	int					id;
	struct s_chain		*chain;
	struct s_anthill	*next;
}						t_anthill;

typedef struct			s_chain
{
	char				*nombre;
	int					id;
	int					start;
	int					end;
	struct s_chain		*next;
	struct s_chain		*prev;
	t_anthill			*ngbr;
}						t_chain;

int						ft_ishash(int c);
int						is_first_line(char *line, t_input *input);
int						is_comment(char	*line);
void					fill_input(t_input *input);
void					error_message(t_input *input);
int						is_room(char *line, t_input *input);
int						is_link(char *line, t_input *input);
int						is_valid_link(char *line,
						t_input *input, t_anthill **room);
int						count_symbols(char *line, int c);
int						found_name(char *new_name, t_anthill **room);
int						correct_link(char *line);
int						is_all_digits(char *line);
int						ft_is_start(char *line, t_input *input);
int						empty_line(char *line);
int						ft_is_end(char *line, t_input *input);
int						verify_input(t_anthill *room, t_input *input);
void					ft_check_line2(t_input *input,
										char **line, t_anthill **room);
void					ft_check_line(t_input *input,
										char **line, t_anthill **room);
int						check_if_r_exists(t_anthill **room,
										char *line, t_input *input);
void					add_line_to_list(t_lines **head, char *line);
t_lines					*backup_line(char *line);
t_anthill				*parse_room(char *line, t_input *input);
void					add_room_to_list(t_anthill **head,
										char *line, t_input *input);
void					add_link_to_list(t_anthill **head,
										char *line, t_input *input);
void					sort_links(t_anthill **room);
t_anthill				*find_start(t_anthill *room, t_input *input);
t_anthill				*find_end(t_anthill *room, t_input *input);
void					ft_clean_parse(char **parse);
void					delete_lines_list(t_lines **head);
void					delete_chain(t_chain *head);
void					delete_rooms_list(t_anthill **head);
t_anthill				*create_queue(t_anthill **room, t_input *input);
void					chain_push_back(t_chain **head, t_chain *new);
void					anthill_push_back(t_anthill **head, t_anthill *new);
t_chain					*create_node(t_anthill *room);
void					add_copy_chain(t_chain **head, t_anthill *room);
t_anthill				*create_next_step(t_anthill *predecessor,
										t_anthill *room);
t_anthill				*create_head(t_anthill *room);
void					clean_q(t_anthill *end, t_anthill **q_head);
void					delete_chain_in_q_element(t_chain *head);
void					count_dist(t_anthill **q_head);
void					count_capacity(t_anthill **que);
void					delete_unneeded(t_anthill **head);
void					print_q(t_anthill *que);
void					output_function(t_anthill *que, t_input *input);
void					output_function1(t_anthill *que, t_input *input);
void					output_one_step(t_anthill *que, t_input *input);
int						is_one_way(t_anthill *que);
void					print_out_input(t_input *input);
void					print_check(t_anthill *room);
void					delete_all_chain(t_anthill *element);
void					delete_all_que(t_anthill **que);
void					delete_all_rooms(t_anthill **room);

#endif
