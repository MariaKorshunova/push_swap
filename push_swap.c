/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:04:05 by jmabel            #+#    #+#             */
/*   Updated: 2022/02/03 17:54:36 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	if (argc == 1)
		return (0);
	i = argc - 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i > 0)
	{
		ft_create_stack(&stack_a, argv[i]);
		i--;
	}
	if (ft_duplicate_sort(stack_a) == 1)
	{
		ft_pop_stack(&stack_a);
		return (0);
	}
	ft_dealer_sorting(&stack_a, &stack_b);
	ft_pop_stack(&stack_a);
	return (0);
}
