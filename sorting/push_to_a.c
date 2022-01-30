/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:32:07 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/30 16:48:59 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*ft_choose_element(t_stack *b)
{
	t_stack	*elem;
	int		min;

	if (!b)
		return (NULL);
	min = b->index;
	elem = b;
	b = b->next;
	while (b)
	{
		if (b->index < min)
		{
			free(elem->steps);
			min = b->index;
			elem = b;
		}
		else
			free(b->steps);
		b = b->next;
	}
	return (elem);
}

void	ft_push_elem_to_a(t_stack **a, t_stack **b)
{
	t_stack	*elem;

	elem = ft_choose_element(*b);
	if ((elem->steps)->scenario == 1)
		ft_scenario_rbrra(a, b, elem);
	else if ((elem->steps)->scenario == 2)
		ft_scenario_rarrb(a, b, elem);
	else if ((elem->steps)->scenario == 3)
		ft_scenario_rr(a, b, elem);
	else if ((elem->steps)->scenario == 4)
		ft_scenario_rrr(a, b, elem);
}

static void	ft_define_index_ra(t_stack *a, t_stack *pos, int *ra)
{
	int		max_index;
	int		max_index_prev;
	t_stack	*tmp;

	*ra = 1;
	max_index = 0;
	max_index_prev = -1;
	tmp = a;
	while (tmp)
	{
		if ((tmp->index > max_index_prev) && (tmp->index < pos->index))
			max_index_prev = tmp->index;
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	if (max_index_prev == -1)
		max_index_prev = max_index;
	while (a->index != max_index_prev)
	{
		(*ra)++;
		a = a->next;
	}
}

void	ft_push_to_a_from_top_b(t_stack **a, t_stack **b, int size_a)
{
	int	ra;

	ft_define_index_ra(*a, *b, &ra);
	if (ra == size_a)
		ra = 0;
	if (ra <= (size_a - ra))
	{
		while (ra > 0)
		{
			ft_r(a, 'a');
			ra--;
		}
	}
	else
	{
		while (ra < size_a)
		{
			ft_rr(a, 'a');
			ra++;
		}
	}
	ft_p(b, a, 'a');
}
