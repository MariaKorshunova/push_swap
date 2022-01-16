/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:04:05 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/15 17:36:15 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Что вывести, если аргументы не поданы?
// If no parameters are specified,
// the program must not display anything and give the prompt back

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = argc - 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i > 0)
	{
		if (ft_create_stack(&stack_a, argv[i--]) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}	
	}
	if (ft_duplicate_sort(stack_a) == 1)
	{
		ft_pop_stack(&stack_a);
		return (0);
	}
	ft_putstr_fd("Init a and b:\n", 1);
	ft_print_stack(stack_a, stack_b);
	ft_putstr_fd("- -\na b\n----------------------------------------------\n", 1);
	ft_putstr_fd("Exec sa:\n", 1);
	ft_s(&stack_a);
	ft_print_stack(stack_a, stack_b);
	ft_putstr_fd("- -\na b\n----------------------------------------------\n", 1);
	ft_putstr_fd("Exec pb pb pb:\n", 1);
	i = 3;
	while (i > 0)
	{
		ft_p(&stack_a, &stack_b);
		i--;
	}
	ft_print_stack(stack_a, stack_b);
	ft_putstr_fd("- -\na b\n----------------------------------------------\n", 1);
	ft_putstr_fd("Exec ra rb (equiv. to rr):\n", 1);
	ft_r(&stack_a);
	ft_r(&stack_b);
	ft_print_stack(stack_a, stack_b);
	ft_putstr_fd("- -\na b\n----------------------------------------------\n", 1);
	ft_putstr_fd("Exec rra rrb (equiv. to rrr):\n", 1);
	ft_rr(&stack_a);
	ft_rr(&stack_b);
	ft_print_stack(stack_a, stack_b);
	ft_putstr_fd("- -\na b\n----------------------------------------------\n", 1);
	ft_pop_stack(&stack_a);
	ft_pop_stack(&stack_b);
	return (0);
}
