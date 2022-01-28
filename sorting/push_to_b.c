/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:01:12 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/28 18:57:12 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_check_sort(t_stack *a, t_stack *pos, int *prev)
{
	int	status;

	status = 0;
	if ((a->min->number < a->median->number) && (a->median->number < a->max->number))
	{
		if ((pos->number > a->min->number) && (pos->number < a->median->number)
			&& (pos->content > *prev) && (pos->content < a->median->content))
		{
			*prev = pos->content;
			status = 1;
		}
		if ((pos->number > a->median->number) && (pos->number < a->max->number)
			&& (pos->content > *prev) && (pos->content > a->median->content))
		{
			*prev = pos->content;
			status = 1;
		}
	}
	if ((a->min->number < a->max->number) && (a->max->number < a->median->number))
	{
		if ((pos->number > a->min->number) && (pos->number < a->max->number)
			&& (pos->content > *prev) && (pos->content < a->median->content))
		{
			*prev = pos->content;
			status = 1;
		}
	}
	if ((a->median->number < a->min->number) && (a->min->number < a->max->number))
	{
		if ((pos->number > a->min->number) && (pos->number < a->max->number)
			&& (pos->content > *prev) && (pos->content < a->median->content))
		{
			*prev = pos->content;
			status = 1;
		}
	}
	return (status);
}

static void	ft_sort_a(t_stack *begin_a, t_stack **a)
{
	if ((begin_a->min->number < begin_a->max->number)
		&& (begin_a->max->number < begin_a->median->number))
	{
		ft_rr(a, 'a');
		ft_rr(a, 'a');
		ft_s(a, 'a');
	}
	if ((begin_a->median->number < begin_a->min->number)
		&& (begin_a->min->number < begin_a->max->number))
	{
		ft_rr(a, 'a');
		ft_s(a, 'a');
	}
}

void	ft_push_elem_to_b(t_stack **a, t_stack **b, int size)
{
	t_stack	*begin_a;
	int		count;
	int		prev;

	begin_a = *a;
	(*a)->min = *a;
	(*a)->max = *a;
	ft_search_min_max(begin_a, &(begin_a->min), &(begin_a->max));
	prev = begin_a->min->content;
	// ft_print_stack(*a, *b);
	// ft_print_stack((*a)->median, NULL);
	count = size;
	while (count > 0)
	{
		if (!((*a)->index == 0) && !((*a)->index == size - 1)
			&& ((*a) != begin_a->median) && (ft_check_sort(begin_a, *a, &prev) == 0))
		{
			ft_p(a, b, 'b');
			if ((*b)->next && ((*b)->content > begin_a->median->content))
				ft_r(b, 'b'); 
		}
		else
			ft_r(a, 'a');
		count--;
		// ft_putstr_fd("count:", 1);
		// ft_putnbr_fd(count, 1);
		// ft_putstr_fd("\n", 1);
		// ft_print_stack(*a, *b);
		// ft_putstr_fd("-------------\n", 1);
	}
	if (ft_stacksize(*a) > 3)
		ft_sort_a(begin_a, a);
	else
		ft_sort_three(a, 'a');
	// ft_print_stack(*a, *b);
}
