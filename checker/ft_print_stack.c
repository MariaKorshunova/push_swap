/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:25:52 by jmabel            #+#    #+#             */
/*   Updated: 2022/02/03 21:28:13 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
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

static void	ft_max_len_value(t_stack *s, int *max_len_value)
{
	*max_len_value = 0;
	while (s)
	{
		if (ft_longlen(s->content) > *max_len_value)
			*max_len_value = ft_longlen(s->content);
		s = s->next;
	}
}

void	ft_print_stack(t_stack *a, t_stack *b)
{
	int	valuea;
	int	valueb;

	ft_max_len_value(a, &valuea);
	ft_max_len_value(b, &valueb);
	while (a || b)
	{
		if (a)
		{		
			printf("%*d", valuea, a->content);
			a = a->next;
		}
		else
			printf("%*.0d", valuea, 0);
		if (b)
		{
			printf("%*d", valueb, b->content);
			b = b->next;
		}
		printf("\n");
	}
}
