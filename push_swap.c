/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:04:05 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/28 17:29:11 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// else if ((size >= 4) && (size <= 6))
	// 	ft_index_sort(&stack_a, &stack_b, size);
	else
		ft_qsort_stack(&stack_a, &stack_b, size);
	// ft_print_stack(stack_a, stack_b);
	ft_pop_stack(&stack_a);
	return (0);
}
