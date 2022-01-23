/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:25:52 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/23 14:09:52 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

static int	ft_longlen(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		len++;
		n = n / 10;
	}
	return (len + 1);
}

static void	ft_max_len_value(t_stack *s, int *max_len_index, int *max_len_value)
{
	*max_len_index = 0;
	*max_len_value = 0;
	while (s)
	{
		if (ft_longlen(s->index) > *max_len_index)
			*max_len_index = ft_longlen(s->index);
		if (ft_longlen(s->content) > *max_len_value)
			*max_len_value = ft_longlen(s->content);
		s = s->next;
	}
}

static void	ft_print_signature(int indexa, int valuea, int indexb, int valueb)
{
	printf("%-*s %-*s\n", indexa + valuea + 3, "-", indexb + valueb + 3, "-");
	printf("%-*s %-*s\n", indexa + valuea + 3, "a", indexb + valueb + 3, "b");
}

void	ft_print_stack(t_stack *a, t_stack *b)
{
	int	indexa;
	int	valuea;
	int	indexb;
	int	valueb;

	ft_max_len_value(a, &indexa, &valuea);
	ft_max_len_value(b, &indexb, &valueb);
	while (a || b)
	{
		if (a)
		{
			printf("[%*d] %*d ", indexa, a->index, valuea, a->content);
			a = a->next;
		}
		else
			printf(" %*.0d  %*.0d ", indexa, 0, valuea, 0);
		if (b)
		{
			printf("[%*d] %*d", indexb, b->index, valueb, b->content);
			b = b->next;
		}
		printf("\n");
	}
	ft_print_signature(indexa, valuea, indexb, valueb);
}

void	ft_print_steps(t_stack *s)
{
	printf("Steps for element from b: [%d] %d\n", s->index, s->content);
	printf("ra: %d\nrra: %d\nrb: %d\nrrb: %d\nsize_a: %d\nsize_b: %d\nscenario: %d\n",
		(s->steps)->ra, (s->steps)->rra, (s->steps)->rb, (s->steps)->rrb,
		(s->steps)->size_a, (s->steps)->size_b, (s->steps)->scenario);
}
