#include "../includes/push_swap.h"

t_lst				*put_lst_end(t_lst *start, t_lst *new)
{
	t_lst		*end;

	end = start;
	if (!start)
		return (new);
	while (end->next != start)
		end = end->next;
	end->next = new;
	new->prev = end;
	new->next = start;
	start->prev = new;
	return (start);
}
