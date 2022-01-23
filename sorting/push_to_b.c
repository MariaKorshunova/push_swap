/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:01:12 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/23 15:02:09 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_push_to_tail(t_stack **a, t_stack **b, int size, int median)
{
	int	rr;

	rr = 0;
	if ((*b)->content > median)
	{
		if ((*a)->next && ((*a)->next)->next)
		{
			if ((*a)->index == 0 || (*a)->index == size - 1)
				rr = ft_ra_rb(a, b);
		}
		if (rr == 0)
			ft_r(b, 'b');
	}		
}

void	ft_push_elem_to_b(t_stack **a, t_stack **b, int size)
{
	int		median;
	int		count;

	median = ((*a)->median)->content;
	count = size;
	while (count > 3)
	{
		if (!((*a)->index == 0) && !((*a)->index == size - 1)
			&& ((*a) != (*a)->median))
		{
			ft_p(a, b, 'b');
			ft_push_to_tail(a, b, size, median);
			count--;
		}
		else
			ft_r(a, 'a');
	}
	ft_sort_three(a, 'a');
}
