/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:23:49 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/27 15:09:11 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_median(t_stack *stack, int size)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (size % 2 == 0)
		{
			if (tmp->index == (size - 1) / 2)
				stack->median = tmp;
		}
		else if (size % 2 == 1)
		{
			if (tmp->index == -1)
				stack->median = tmp;
		}
		tmp = tmp->next;
	}
}

static void	ft_min_max_index(t_stack **stack, t_stack **min, t_stack **max)
{
	if (!stack || !min || !max)
		return ;
	while (*stack)
	{
		if ((*stack)->content > (*max)->content && (*stack)->index < 0)
			*max = *stack;
		else if ((*stack)->content < (*min)->content && (*stack)->index < 0)
			*min = *stack;
		*stack = (*stack)->next;
	}
}

void	ft_indexing_stack(t_stack **stack, int size)
{
	int		i;
	t_stack	*tmp;
	t_stack	*min;
	t_stack	*max;

	i = 0;
	while (i < size / 2)
	{
		tmp = *stack;
		while (tmp->index >= 0)
			tmp = tmp->next;
		min = tmp;
		max = tmp;
		ft_min_max_index(&tmp, &min, &max);
		min->index = i;
		max->index = size - i - 1;
		i++;
	}
	ft_median(*stack, size);
}

void	ft_serial_number(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		s->number = i;
		i++;
		s = s->next;
	}
}
