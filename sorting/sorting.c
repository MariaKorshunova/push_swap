/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:53:58 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/30 17:09:26 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_dealer_sorting(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stacksize(*stack_a);
	if (size == 2)
		ft_s(stack_a, 'a');
	else if (size == 3)
	{
		ft_sort_three(stack_a, 'a');
		ft_min_to_top(stack_a, size);
	}
	else if ((size >= 4) && (size <= 6))
		ft_triple_sort(stack_a, stack_b, size);
	else
		ft_qsort_stack(stack_a, stack_b, size);
}

void	ft_qsort_stack(t_stack **a, t_stack **b, int size)
{
	int	count;
	int	size_a;

	count = size;
	ft_indexing_stack(a, size);
	ft_serial_number(*a);
	ft_push_elem_to_b(a, b, size);
	size_a = ft_stacksize(*a);
	while (count > size_a)
	{
		ft_count_operations(*a, *b);
		ft_push_elem_to_a(a, b);
		count--;
	}
	ft_min_to_top(a, size);
}

void	ft_triple_sort(t_stack **a, t_stack **b, int size)
{
	int		count;

	count = size;
	ft_indexing_stack(a, size);
	while (count > 3)
	{
		ft_p(a, b, 'b');
		count--;
	}
	ft_sort_three(a, 'a');
	while (*b)
	{
		ft_push_to_a_from_top_b(a, b, count);
		count++;
	}
	ft_min_to_top(a, size);
}

void	ft_sort_three(t_stack **s, char c)
{
	t_stack	*min;
	t_stack	*max;

	min = *s;
	max = *s;
	if (!s)
		return ;
	if (ft_stacksize(*s) != 3)
		return ;
	ft_search_min_max(*s, &min, &max);
	if ((*s == min && (*s)->next == max)
		|| (*s == max && (*s)->next->next == min)
		|| ((*s)->next == min && (*s)->next->next == max))
		ft_s(s, c);
}

void	ft_min_to_top(t_stack **a, int size)
{
	t_stack	*min;
	t_stack	*tmp;
	int		size_min;

	tmp = *a;
	min = tmp;
	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	size_min = ft_stacksize(min);
	while (*a != min)
	{
		if (size_min <= size / 2)
			ft_rr(a, 'a');
		else
			ft_r(a, 'a');
	}
}
