/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:04:05 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/22 17:43:44 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// Что вывести, если аргументы не поданы?
// If no parameters are specified,
// the program must not display anything and give the prompt back

//Another algorithm for stack with size <= 6

// free(b->steps) после действия

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		size;

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
	ft_indexing_stack(&stack_a, size);
	ft_push_elem_to_b(&stack_a, &stack_b, size, ft_stacksize(stack_a->median));
	ft_count_operations(stack_a, stack_b);
	ft_print_stack(stack_a, stack_b);
	i = argc - 3;
	while (i > 0)
	{
		ft_push_elem_to_a(&stack_a, &stack_b);
		i--;
	}
	ft_pop_stack(&stack_a);
	ft_pop_stack(&stack_b);
	return (0);
}
