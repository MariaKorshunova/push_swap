/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:24:03 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/15 17:36:01 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_s(t_stack **stack)
{
	t_stack	*second;
	t_stack	*third;

	if (!(*stack) || !(*stack)->next)
		return ;
	second = *stack;
	third = (*stack)->next->next;
	*stack = (*stack)->next;
	(*stack)->next = second;
	(*stack)->next->next = third;
}

void	ft_p(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*tmp;

	if (!stack_src || !stack_dest)
		return ;
	if (!(*stack_src))
		return ;
	tmp = (*stack_src)->next;
	(*stack_src)->next = NULL;
	ft_push(stack_dest, *stack_src);
	*stack_src = tmp;
}

void	ft_r(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	last = *stack;
	*stack = (*stack)->next;
	tmp = *stack;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = last;
	tmp->next->next = NULL;
}

void	ft_rr(t_stack **stack)
{
	t_stack	*begin;
	t_stack	*tmp;
	int		size;

	begin = *stack;
	tmp = *stack;
	size = ft_stacksize(*stack);
	while (size > 2)
	{
		tmp = tmp->next;
		size--;
	}
	*stack = tmp->next;
	tmp->next = NULL;
	(*stack)->next = begin;
}
