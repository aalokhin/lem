#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>



typedef struct 		s_input
{
	int				error;
	int 			ant_nr;
	int				start;
	int				end;
	int				
	int				
}					t_input;



typedef struct 		s_room
{
	char			*name;
	int 			x;
	int 			y;
	struct 			s_room *next;
}					t_room;

typedef struct 		s_link
{

}					t_link;


int				ft_ishash(int c);
int 			is_first_line(char	*line); //is forst line

int 			is_comment(char	*line);

int 		is_room(char *line);//if the room is correct

int 		is_link(char *line);

int 	correct_link(char *line);

int			ft_check_map_2(t_input *input);// shoudl return 1 if ok and 0 if error

int			ft_check_map_1(t_input **input);// shoudl return 1 if ok and 0 if error




#endif


// 3
// ##start
// 0 1 0
// ##end
// 1 5 0
// 2 9 0
// 3 13 0
// 0-2
// 2-3
// 3-1