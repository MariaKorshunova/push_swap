/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:35:49 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/15 14:11:04 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_atoi_sign(const char *str, int *i)
{
	while (!(ft_isprint(str[*i])))
		(*i)++;
	if (str[*i] == '+')
		(*i)++;
	else if (str[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	return (1);
}

static	int	ft_create_nb(const char *str, int *i, long long *nb)
{
	size_t			nb_digit;

	nb_digit = 0;
	while (str[*i] == '0')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*nb = 10 * (*nb) + str[(*i)++] - '0';
		nb_digit++;
	}
	while (ft_isprint(str[*i]) == 0 && str[*i] != '\0')
		(*i)++;
	return (nb_digit);
}

int	ft_atoi_check_digits(const char *str)
{
	int				i;
	int				minus;
	long long		nb;
	size_t			nb_digit;

	i = 0;
	nb = 0;
	nb_digit = 0;
	minus = ft_atoi_sign(str, &i);
	if (str[i] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	nb_digit = ft_create_nb(str, &i, &nb);
	if (str[i] != '\0' || (nb > 2147483647 && minus == 1)
		|| (nb > 2147483648 && minus == -1) || nb_digit > 11)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	return (minus * nb);
}

int	ft_duplicate_sort(t_stack *stack)
{
	t_stack	*stack_next;
	int		check_sort;

	check_sort = 1;
	while (stack->next)
	{
		stack_next = stack->next;
		while (stack_next)
		{
			if (stack->content == stack_next->content)
			{
				ft_putstr_fd("Error\n", 2);
				exit (1);
			}
			if (stack->content > stack_next->content)
				check_sort = 0;
			stack_next = stack_next->next;
		}
		stack = stack->next;
	}
	return (check_sort);
}
