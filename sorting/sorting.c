/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:29:46 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/17 17:34:52 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_median_to_b(t_stack **a, t_stack **b, int size, int size_median)
{
	t_stack	*median;

	median = (*a)->median;
	while (median != *a)
	{
		if (size_median <= size / 2)
			ft_rr(a, 'a');
		else
			ft_r(a, 'a');
	}
	ft_p(a, b, 'b');
}

void	ft_push_elem_to_b(t_stack **a, t_stack **b, int size, int size_median)
{
	int		median;
	int		count;
	int		rr;

	median = ((*a)->median)->content;
	ft_median_to_b(a, b, size, size_median);
	count = size - 1;
	while (count > 2)
	{
		rr = 0;
		if (!((*a)->index == 0) && !((*a)->index == size - 1))
		{
			ft_p(a, b, 'b');
			if ((*b)->content > median)
			{
				if ((*a)->next && ((*a)->next)->next)
				{
					if (((*a)->next)->index == 0 || ((*a)->next)->index == size - 1)
					{
						ft_ra_rb(a, b);
						rr = 1;
					}
				}
				if (rr == 0)
					ft_r(b, 'b');
			}
			count--;
		}
		else
			ft_r(a, 'a');
		ft_print_stack(*a, *b);
	}
}
