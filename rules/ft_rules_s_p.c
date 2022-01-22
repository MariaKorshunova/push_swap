/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_s_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:21:52 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/22 16:23:16 by jmabel           ###   ########.fr       */
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

void	ft_p(t_stack **stack_src, t_stack **stack_dest, char c)
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
	ft_putchar_fd('p', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}
