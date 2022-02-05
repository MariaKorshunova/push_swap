/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_s_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:21:52 by jmabel            #+#    #+#             */
/*   Updated: 2022/02/05 12:15:24 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_s(t_stack **stack, char c)
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
	if (c == 'a' || c == 'b')
	{
		ft_putchar_fd('s', 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ft_ss(t_stack **a, t_stack **b, char c)
{
	ft_s(a, '0');
	ft_s(b, '0');
	if (c == '0')
		ft_putstr_fd("ss\n", 1);
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
	if (c == 'a' || c == 'b')
	{
		ft_putchar_fd('p', 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
}
