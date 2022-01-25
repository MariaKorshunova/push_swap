/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:04:05 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/25 16:48:52 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Another algorithms for stack with size <= 6

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		size;
	int		count;

	if (argc == 1)
		return (0);
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
	size = ft_stacksize(stack_a);
	count = size;
	if (size == 2)
		ft_s(&stack_a, 'a');
	else if (size == 3)
	{
		ft_sort_three(&stack_a, 'a');
		ft_min_to_top(&stack_a, size);
	}
	else if ((size >= 4) && (size <= 6))
	{
		ft_print_stack(stack_a, stack_b);
		while (size > 3)
		{
			ft_p(&stack_a, &stack_b, 'b');
			size--;
		}
		ft_print_stack(stack_a, stack_b);
		ft_sort_three(&stack_a, 'a');
		ft_putstr_fd("sort_three\n", 1);
		ft_print_stack(stack_a, stack_b);
		ft_count_operations(stack_a, stack_b);
		ft_print_steps(stack_b);
		while (count > 3)
		{
			ft_push_elem_to_a(&stack_a, &stack_b);
			count--;
			ft_print_stack(stack_a, stack_b);
		}
		ft_min_to_top(&stack_a, size);
	}
	else
		ft_qsort_stack(&stack_a, &stack_b, size);
	// ft_print_stack(stack_a, stack_b);
	ft_pop_stack(&stack_a);
	return (0);
}
