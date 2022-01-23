/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:03:31 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/23 16:39:41 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_define_ra(t_stack *a, t_stack *pos, t_steps **stepsnode)
{
	while (a && (pos->content < a->content))
	{
		((*stepsnode)->ra)++;
		a = a->next;
	}
	while (a && (pos->content > a->content))
	{
		((*stepsnode)->ra)++;
		a = a->next;
	}
	if ((*stepsnode)->ra == (*stepsnode)->size_a)
		(*stepsnode)->ra = 0;
}

static void	ft_define_operations(t_stack *a, t_stack *b, t_stack *pos)
{
	t_steps	*stepsnode;

	if (!a || !b)
		return ;
	stepsnode = ft_node_steps(ft_stacksize(a), ft_stacksize(b));
	if (!stepsnode)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	while (b && b != pos)
	{
		(stepsnode->rb)++;
		b = b->next;
	}
	ft_define_ra(a, pos, &stepsnode);
	stepsnode->rra = stepsnode->size_a - stepsnode->ra;
	stepsnode->rrb = stepsnode->size_b - stepsnode->rb;
	pos->steps = stepsnode;
	return ;
}

static int	ft_min_in_fours(int a, int b, int c, int d)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	if (d < min)
		min = d;
	return (min);
}

static int	ft_min_operations(t_steps *s)
{
	int	sc1;
	int	sc2;
	int	sc3;
	int	sc4;

	sc1 = s->rb + s->size_a - s->ra;
	sc2 = s->size_b - s->rb + s->ra;
	if (s->ra >= s->rb)
		sc3 = s->ra;
	else
		sc3 = s->rb;
	if ((s->size_a - s->ra) >= (s->size_b - s->rb))
		sc4 = s->size_a - s->ra;
	else
		sc4 = s->size_b - s->rb;
	return (ft_min_in_fours(sc1, sc2, sc3, sc4));
}

void	ft_count_operations(t_stack *a, t_stack *b)
{
	t_stack	*begin_b;

	if (!a || !b)
		return ;
	begin_b = b;
	while (b)
	{
		ft_define_operations(a, begin_b, b);
		b->index = ft_min_operations(b->steps);
		if (b->index == ((b->steps)->rb + (b->steps)->size_a - (b->steps)->ra))
			(b->steps)->scenario = 1;
		if (b->index == ((b->steps)->size_b - (b->steps)->rb + (b->steps)->ra))
			(b->steps)->scenario = 2;
		if ((((b->steps)->ra >= (b->steps)->rb) && b->index == (b->steps)->ra)
			|| (((b->steps)->ra < (b->steps)->rb)
				&& b->index == (b->steps)->rb))
			(b->steps)->scenario = 3;
		b = b->next;
	}	
}
