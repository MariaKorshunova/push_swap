/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:59:36 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/23 16:32:18 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_steps	*ft_node_steps(int size_a, int size_b)
{
	t_steps	*stepsnew;

	stepsnew = malloc(sizeof(t_stack));
	if (stepsnew == NULL)
		return (NULL);
	stepsnew->ra = 0;
	stepsnew->rb = 0;
	stepsnew->rra = 0;
	stepsnew->rrb = 0;
	stepsnew->size_a = size_a;
	stepsnew->size_b = size_b;
	stepsnew->scenario = 4;
	return (stepsnew);
}

int	ft_stacksize(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

void	ft_search_min_max(t_stack **stack, t_stack **min, t_stack **max)
{
	if (!stack || !min || !max)
		return ;
	while (*stack)
	{
		if ((*stack)->content > (*max)->content)
			*max = *stack;
		else if ((*stack)->content < (*min)->content)
			*min = *stack;
		*stack = (*stack)->next;
	}
}
