/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:12:29 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/30 22:21:25 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*ft_create_node(void *content)
{
	t_stack	*stacknew;

	stacknew = malloc(sizeof(t_stack));
	if (stacknew == NULL)
		return (NULL);
	stacknew->content = *((int *)content);
	stacknew->next = NULL;
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

static	int	ft_strncmp_ps(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0' )
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] != '\0' || s2[i] != '\0')
		return (-1);
	return (0);
}

int	ft_create_stack(t_stack **stack_a, char *str, char **output)
{
	t_stack	*stacknew;
	int		nb;
	int		flag_error;
	char	*str;

	flag_error = 0;
	nb = ft_atoi_check_digits(str, &flag_error);
	if (flag_error == -1)
	{
		*output = get_next_line(0);
		if (ft_strncmp_ps("Error\n", *output) == 0 && get_next_line(0) == NULL)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		ft_pop_stack(stack_a);
		return (-1);
	}
	stacknew = ft_create_node(&nb);
	if (!stacknew)
	{
		ft_pop_stack(stack_a);
		exit (1);
	}
	ft_push(stack_a, stacknew);
	return (0);
}
