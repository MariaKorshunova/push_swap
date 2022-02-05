/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:51:47 by jmabel            #+#    #+#             */
/*   Updated: 2022/02/05 13:41:40 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../get_next_line/get_next_line.h"

static int	ft_strncmp_ps(const char *s1, const char *s2)
{
	int	i;

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

static int	ft_do_instruction(t_stack **a, t_stack **b, char **s)
{
	if (ft_strncmp_ps(*s, "sa\n") == 0)
		ft_s(a, 'c');
	else if (ft_strncmp_ps(*s, "sb\n") == 0)
		ft_s(b, 'c');
	else if (ft_strncmp_ps(*s, "ss\n") == 0)
		ft_ss(a, b, 'c');
	else if (ft_strncmp_ps(*s, "pa\n") == 0)
		ft_p(b, a, 'c');
	else if (ft_strncmp_ps(*s, "pb\n") == 0)
		ft_p(a, b, 'c');
	else if (ft_strncmp_ps(*s, "ra\n") == 0)
		ft_r(a, 'c');
	else if (ft_strncmp_ps(*s, "rb\n") == 0)
		ft_r(b, 'c');
	else if (ft_strncmp_ps(*s, "rr\n") == 0)
		ft_ra_rb(a, b, 'c');
	else if (ft_strncmp_ps(*s, "rra\n") == 0)
		ft_rr(a, 'c');
	else if (ft_strncmp_ps(*s, "rrb\n") == 0)
		ft_rr(b, 'c');
	else if (ft_strncmp_ps(*s, "rrr\n") == 0)
		ft_rra_rrb(a, b, 'c');
	else
		return (-1);
	return (1);
}

static void	ft_check_sort(t_stack **a, t_stack **b)
{
	if (ft_duplicate_sort(*a) == 1 && !(*b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_pop_stack(a);
	ft_pop_stack(b);
}

void	ft_parser(t_stack **a)
{
	t_stack	*b;
	char	*instruction;
	int		ret;

	b = NULL;
	ret = 1;
	while (ret)
	{
		instruction = get_next_line(0);
		if (instruction == NULL)
			ret = 0;
		else
		{
			if (ft_do_instruction(a, &b, &instruction) == -1)
			{
				ft_putstr_fd("Error\n", 1);
				free(instruction);
				ft_pop_stack(a);
				ft_pop_stack(&b);
				return ;
			}
		}
		free(instruction);
	}
	ft_check_sort(a, &b);
}
