/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:01:12 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/28 20:55:53 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_new_previous(t_stack *pos, int *prev, int *status)
{
	*prev = pos->content;
	*status = 1;
}

static void	ft_check_sort_add(t_stack *a, t_stack *pos, int *prev, int *status)
{
	if ((a->min->number < a->median->number)
		&& (a->median->number < a->max->number))
	{
		if ((pos->number < a->median->number)
			&& (pos->content < a->median->content))
			ft_new_previous(pos, prev, status);
		else if ((pos->number > a->median->number)
			&& (pos->number < a->max->number)
			&& (pos->content > a->median->content))
			ft_new_previous(pos, prev, status);
	}
	else if ((a->max->number < a->min->number)
		&& (a->min->number < a->median->number))
	{
		if ((pos->number < a->median->number)
			&& (pos->content < a->median->content))
			ft_new_previous(pos, prev, status);
		else if ((pos->number > a->median->number)
			&& (pos->content > a->median->content))
			ft_new_previous(pos, prev, status);
	}
	else if ((a->max->number < a->median->number)
		&& (a->median->number < a->min->number)
		&& (pos->content < a->median->content))
		ft_new_previous(pos, prev, status);
}

static int	ft_check_sort(t_stack *a, t_stack *pos, int *prev)
{
	int	status;

	status = 0;
	if ((pos->number > a->min->number) && (pos->content > *prev))
	{
		if ((a->min->number < a->max->number)
			&& (a->max->number < a->median->number)
			&& (pos->number < a->max->number)
			&& (pos->content < a->median->content))
			ft_new_previous(pos, prev, &status);
		else if ((a->median->number < a->min->number)
			&& (a->min->number < a->max->number)
			&& (pos->number < a->max->number)
			&& (pos->content < a->median->content))
			ft_new_previous(pos, prev, &status);
		else if ((a->median->number < a->max->number)
			&& (a->max->number < a->min->number)
			&& (pos->content < a->median->content))
			ft_new_previous(pos, prev, &status);
		else
			ft_check_sort_add(a, pos, prev, &status);
	}
	return (status);
}

static void	ft_sort_a(t_stack *begin, t_stack **a)
{
	if ((begin->min->number < begin->max->number)
		&& (begin->max->number < begin->median->number))
	{
		ft_rr(a, 'a');
		ft_rr(a, 'a');
		ft_s(a, 'a');
	}
	else if ((begin->median->number < begin->min->number)
		&& (begin->min->number < begin->max->number))
	{
		ft_rr(a, 'a');
		ft_s(a, 'a');
	}
	else if ((begin->median->number < begin->max->number)
		&& (begin->max->number < begin->min->number))
	{
		ft_r(a, 'a');
		ft_r(a, 'a');
	}
	else if ((begin->max->number < begin->min->number)
		&& (begin->min->number < begin->median->number))
		ft_r(a, 'a');
	else if ((begin->max->number < begin->median->number)
		&& (begin->median->number < begin->min->number))
		ft_s(a, 'a');
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
	count = size;
	while (count > 0)
	{
		if (!((*a)->index == 0) && !((*a)->index == size - 1)
			&& ((*a) != begin_a->median)
			&& (ft_check_sort(begin_a, *a, &prev) == 0))
		{
			ft_p(a, b, 'b');
			if ((*b)->next && ((*b)->content > begin_a->median->content))
				ft_r(b, 'b');
		}
		else
			ft_r(a, 'a');
		count--;
	}
	ft_sort_a(begin_a, a);
}
