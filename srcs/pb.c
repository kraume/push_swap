#include "../includes/push_swap.h"

void		stack_b_not_empty(t_lst **head_a, t_lst **head_b, t_lst *end_a)
{
	t_lst	*end_b;
	t_lst	*first;

	(*head_a)->next->size = (*head_a)->size - 1;
	(*head_a)->next->prev = end_a;
	end_a->next = (*head_a)->next;
	end_b = *head_b;
	while (end_b->next && end_b->next != (*head_b))
		end_b = end_b->next;
	first = (*head_a);
	(*head_a) = (*head_a)->next;
	first->next = (*head_b);
	(*head_b)->prev = first;
	end_b->next = first;
	first->prev = end_b;
	first->size = (*head_b)->size++;
}

void		stack_b_is_empty(t_lst **head_a, t_lst **head_b, t_lst *end_a)
{
	(*head_a)->next->size = (*head_a)->size - 1;
	(*head_b) = *head_a;
	(*head_a)->next->prev = end_a;
	end_a->next = (*head_a)->next;
	(*head_b)->size = 1;
	(*head_a) = (*head_a)->next;
	end_a->next = (*head_a);
	(*head_a)->prev = end_a;
	(*head_b)->next = (*head_b);
	(*head_b)->prev = (*head_b);
	(*head_b)->size = 1;
}

int			pb(t_lst **head_a, t_lst **head_b)
{
	t_lst	*end_a = NULL;

	end_a = *head_a;
	while (end_a->next && end_a->next != (*head_a))
		end_a = end_a->next;
	if (!*head_b && (*head_a)->size)
	{
		stack_b_is_empty(head_a, head_b, end_a);
		return (1);
	}
	if (*head_b && (*head_a)->size)
	{
		stack_b_not_empty(head_a, head_b, end_a);
		return (1);
	}
	return (0);
}