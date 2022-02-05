/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:21:26 by jmabel            #+#    #+#             */
/*   Updated: 2022/02/05 10:49:36 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_r(t_stack **stack, char c)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!((*stack)->next))
		return ;
	last = *stack;
	*stack = (*stack)->next;
	tmp = *stack;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = last;
	tmp->next->next = NULL;
	if (c == 'a' || c == 'b')
	{
		ft_putchar_fd('r', 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
}

int	ft_ra_rb(t_stack **a, t_stack **b, char c)
{
	ft_r(a, '0');
	ft_r(b, '0');
	if (c == '0')
		ft_putstr_fd("rr\n", 1);
	return (1);
}

void	ft_rr(t_stack **stack, char c)
{
	t_stack	*begin;
	t_stack	*tmp;
	int		size;

	if (!(*stack)->next)
		return ;
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
	if (c == 'a' || c == 'b')
	{
		ft_putstr_fd("rr", 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
}

int	ft_rra_rrb(t_stack **a, t_stack **b, char c)
{
	ft_rr(a, '0');
	ft_rr(b, '0');
	if (c == '0')
		ft_putstr_fd("rrr\n", 1);
	return (1);
}
