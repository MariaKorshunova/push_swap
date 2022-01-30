/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:54:40 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/30 19:24:18 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_create_node(void *content)
{
	t_stack	*stacknew;

	stacknew = malloc(sizeof(t_stack));
	if (stacknew == NULL)
		return (NULL);
	stacknew->content = *((int *)content);
	stacknew->index = -1;
	stacknew->next = NULL;
	stacknew->min = NULL;
	stacknew->max = NULL;
	stacknew->steps = NULL;
	return (stacknew);
}

void	ft_push(t_stack **stack, t_stack *new)
{
	if (!new || !stack)
		return ;
	if (!(*stack))
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

void	ft_pop_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	tmp = *stack;
	while (tmp)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	ft_create_stack(t_stack **stack_a, char *str)
{
	t_stack	*stacknew;
	int		nb;

	nb = ft_atoi_check_digits(str);
	stacknew = ft_create_node(&nb);
	if (!stacknew)
	{
		ft_pop_stack(stack_a);
		return (-1);
	}
	ft_push(stack_a, stacknew);
	return (0);
}
