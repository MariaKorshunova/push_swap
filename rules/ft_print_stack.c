/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:25:52 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/17 16:19:36 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_stack(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_putchar_fd('[', 1);
			ft_putnbr_fd(stack_a->index, 1);
			ft_putstr_fd("] ", 1);
			ft_putnbr_fd(stack_a->content, 1);
			ft_putchar_fd(' ', 1);
			stack_a = stack_a->next;
		}
		else
			ft_putstr_fd("      ", 1);
		if (stack_b)
		{
			ft_putchar_fd('[', 1);
			ft_putnbr_fd(stack_b->index, 1);
			ft_putstr_fd("] ", 1);
			ft_putnbr_fd(stack_b->content, 1);
			ft_putchar_fd(' ', 1);
			stack_b = stack_b->next;
		}
		ft_putchar_fd('\n', 1);
	}
}
