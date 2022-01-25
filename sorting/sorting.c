/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:53:58 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/25 16:10:48 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_three(t_stack **s, char c)
{
	t_stack	*tmp;
	t_stack	*min;
	t_stack	*max;

	tmp = *s;
	min = *s;
	max = *s;
	if (!s)
		return ;
	if (ft_stacksize(*s) != 3)
		return ;
	ft_search_min_max(&tmp, &min, &max);
	if ((*s == min && (*s)->next == max)
		|| (*s == max && (*s)->next->next == min)
		|| ((*s)->next == min && (*s)->next->next == max))
		ft_s(s, c);
}

void	ft_qsort_stack(t_stack **a, t_stack **b, int size)
{
	int	count;

	count = size;
	ft_indexing_stack(a, size);
	ft_push_elem_to_b(a, b, size);
	ft_count_operations(*a, *b);
	while (count > 3)
	{
		ft_push_elem_to_a(a, b);
		count--;
	}
	ft_min_to_top(a, size);
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
