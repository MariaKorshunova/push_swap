/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:27:53 by jmabel            #+#    #+#             */
/*   Updated: 2022/02/03 21:33:14 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

static void	ft_check_empty(void)
{
	if (get_next_line(0) == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	if (argc == 1)
	{
		ft_check_empty();
		return (0);
	}
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
		ft_check_empty();
		ft_pop_stack(&stack_a);
		return (0);
	}	
	// ret = 1;
	// while (ret)
	// {
	// 	instruction = get_next_line(0);
	// 	ft_putstr_fd(instruction, 1);
	// 	if (instruction == NULL)
	// 		ret = 0;
	// }
	ft_print_stack(stack_a, NULL);
	return (0);
}
