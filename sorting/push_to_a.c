/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:32:07 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/25 20:32:18 by jmabel           ###   ########.fr       */
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
