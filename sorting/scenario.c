/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenario.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:48:12 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/23 12:39:24 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_scenario_rbrra(t_stack **a, t_stack **b, t_stack *elem)
{
	while ((elem->steps)->rb > 0)
	{
		ft_r(b, 'b');
		((elem->steps)->rb)--;
	}
	while ((elem->steps)->rra > 0)
	{
		ft_rr(a, 'a');
		((elem->steps)->rra)--;
	}
	ft_p(b, a, 'a');
	free(elem->steps);
}

void	ft_scenario_rarrb(t_stack **a, t_stack **b, t_stack *elem)
{
	while ((elem->steps)->rrb > 0)
	{
		ft_rr(b, 'b');
		((elem->steps)->rrb)--;
	}
	while ((elem->steps)->ra > 0)
	{
		ft_r(a, 'a');
		((elem->steps)->ra)--;
	}
	ft_p(b, a, 'a');
	free(elem->steps);
}

void	ft_scenario_rr(t_stack **a, t_stack **b, t_stack *elem)
{
	if ((elem->steps)->ra >= (elem->steps)->rb)
	{
		while ((elem->steps)->ra != (elem->steps)->rb)
		{
			ft_r(a, 'a');
			((elem->steps)->ra)--;
		}
	}
	else
	{
		while ((elem->steps)->rb != (elem->steps)->ra)
		{
			ft_r(b, 'b');
			((elem->steps)->rb)--;
		}
	}
	while ((elem->steps)->ra > 0)
	{
		ft_ra_rb(a, b);
		((elem->steps)->ra)--;
	}
	free(elem->steps);
	ft_p(b, a, 'a');
}

void	ft_scenario_rrr(t_stack **a, t_stack **b, t_stack *elem)
{
	if ((elem->steps)->rra >= (elem->steps)->rrb)
	{
		while ((elem->steps)->rra != (elem->steps)->rrb)
		{
			ft_rr(a, 'a');
			((elem->steps)->rra)--;
		}
	}
	else
	{
		while ((elem->steps)->rrb != (elem->steps)->rra)
		{
			ft_rr(b, 'b');
			((elem->steps)->rrb)--;
		}
	}
	while ((elem->steps)->rra > 0)
	{
		ft_rra_rrb(a, b);
		((elem->steps)->rra)--;
	}
	free(elem->steps);
	ft_p(b, a, 'a');
}
