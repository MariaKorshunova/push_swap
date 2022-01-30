/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:27:53 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/30 22:23:11 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//проверить ft_strncmp_ps с push_swap

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*instruction;
	int		i;
	int		ret;

	(void)argv;
	if (argc == 1)
	{
		// проверить, что push_swap ничего не возвращает
	}
	i = argc - 1;
	stack_a = NULL;
	stack_b = NULL;
	instruction = NULL;
	while (i > 0)
	{
		if (ft_create_stack(&stack_a, argv[i--], instruction) == -1)
			return (0);
	}
	ret = 1;
	while (ret)
	{
		instruction = get_next_line(0);
		ft_putstr_fd(instruction, 1);
		if (instruction == NULL)
			ret = 0;
	}
	return (0);
}
