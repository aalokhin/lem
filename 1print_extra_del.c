#include "lem_in.h"


void		print_q(t_anthill *que)
{
	int 		a;
	t_anthill	*check;
	t_chain		*k;

	if (!que)
	{
		ft_printf("There is no queue at all!\n");
		return ;
	}
	check = que;
	a = 0;
	k = check->chain;
	ft_printf("*~*~*~*~**~*~**~*~**~*~**~*~**~*~*~**~*~**~*~**~*~**~**~*\n");
	ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	while (check != NULL)
	{

		ft_printf("the queu element number %d is  %s with distance of %d\n", a, check->name, check->length);
	ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		k = check->chain;
		while(k != NULL)
		{
	
			ft_printf("cur  is <%s>", k->nombre);
			if (k->start)
				ft_printf(" this room is starting point");
			if (k->end)
				ft_printf(" this is finish");
		
			ft_printf("\n");
			//if (k != check->chain)
			//	ft_printf("prev  <%s>\n", k->prev->ngbr->name);
			k = k->next;
		}
		ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		check = check->next;
		a++;
	}
	ft_printf("*~*~*~*~**~*~**~*~**~*~**~*~**~*~*~**~*~**~*~**~*~**~**~*\n");
}

void		print_check(t_anthill *room)
{
	ft_printf("LETS CHECKIT ALL\n");
	t_anthill *aaa;
	aaa = room;
		t_chain *y;
	while(aaa != NULL)
	{
		ft_printf("name %s  ", aaa->name);
		ft_printf("coordinates: (%d, %d) \n", aaa->x, aaa->y);
		//ft_printf("level of the room %d\n", aaa->lvl);
	
		if (aaa->is_start == 1)
		{
			ft_printf("and this room is the beginning\n");
		}
		if (aaa->is_end == 1)
		{
			ft_printf("and this room is the end\n");
		}
		//ft_printf("is chain invalid %d\n", !(aaa->chain));
		y = aaa->chain;
		while (y != NULL)
		{
			ft_printf("we are linked to a room: \"%s\" \n", y->ngbr->name);
			y = y->next;
		}
		aaa = aaa->next;
	}


	// ft_printf("LETS CHECKIT ALL\n");
	
	// aaa = room;
	// while(aaa != NULL)
	// {
	// 	ft_printf("name %s  ", aaa->name);
	// 	ft_printf("coordinates: (%d, %d) \n", aaa->x, aaa->y);
	// 	//ft_printf("level of the room %d\n", aaa->lvl);
	
	// 	if (aaa->is_start == 1)
	// 	{
	// 		ft_printf("and this room is the beginning\n");
	// 	}
	// 	if (aaa->is_end == 1)
	// 	{
	// 		ft_printf("and this room is the end\n");
	// 	}
	// 	//ft_printf("is chain invalid %d\n", !(aaa->chain));
	// 	t_chain *y;

	// 	y = aaa->chain;

	// 	while (y != NULL)
	// 	{
	// 		ft_printf("we are linked to a room: \"%s\" \n", y->ngbr->name);
	// 		y = y->next;
	// 	}

	// 	aaa = aaa->next;
	// }

	// ft_printf("LET's PRINT OUR BACKED UP DATA\n");
	// t_lines *print = input.lines;
	// while (print)
	// {
	// 	ft_printf("we have a line saved: %s\n", print->save);
	// 	print = print->next;
	// }




	// ft_printf("LET's check if the memory has been freed\n");
	// t_lines *print1 = input.lines;
	// while (print1 != NULL)
	// {
	// 	ft_printf("we have a line saved: %s\n", print1->save);
	// 	print1 = print1->next;
	// }
	
	// while (input.lines->save != NULL)
	// ft_printf("%s\n", input.lines->save);
	
}