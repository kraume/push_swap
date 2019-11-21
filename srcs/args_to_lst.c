#include "../includes/push_swap.h"

static int			num_is_valid(char *ptr)
{
	char	*tmp;

	tmp = ptr;
	while (*tmp && !ft_isblank(*tmp))
	{
		if (!(*tmp >= 0 + '0' && *tmp <= 9 + '0'))
			return (0);
		++tmp;
	}
	return (1);
}

static t_lst	*push_lst_to_end(t_lst *head, t_lst *new)
{
	t_lst		*end;

	if (!head)
	{
		new->next = new;
		new->prev = new;
		return (new);
	}
	end = head;
	while (end->next && end->next != head)
		end = end->next;
	end->next = new;
	new->prev = end;
	new->next = head;
	head->prev = new;
	return (head);
}

int			valid_args(char *ptr, int ac, char  **av)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ptr;
	while (++i < ac)
	{
		ptr = av[i];
		while (*ptr)
		{
			if (!((*ptr >= 0 + '0' && *ptr <= 9 + '0') || *ptr == ' ' || *ptr == '"'))
				return (0);
			++ptr;
		}
	}
	return (1);
}

int			args_to_lst(int ac, char **av, t_lst **head)
{
	int		i;
	char	*ptr;
	// t_lst	*new = NULL;
	// t_lst	*head = NULL;

	i = 0;
	if (valid_args(ptr, ac, av))
	{
		while (++i < ac)
		{
			ptr = av[i];
			while (*ptr)
			{
				while (ft_isblank(*ptr))
					++ptr;
				if ((*ptr >= (0 + '0')) && (*ptr <= (9 + '0')))
			// {
				// if ((num_is_valid(ptr)))
				// {
					(*head = push_lst_to_end(*head, new_lst(ft_atoi(ptr))));
				// }
			// }
				// else
					// return (0);
			// new = NULL;
			// if (!(new = new_lst(ft_atoi(ptr))))
				// return (0);
			// if (!(*head = push_lst_to_end(*head, new_lst(ft_atoi(ptr)))))
				// return (0);
				while (!ft_isblank(*ptr) && *ptr)
					++ptr;
			}
		}
		return (1);
	}
	return (0);
}
