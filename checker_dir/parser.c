/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:51:47 by jmabel            #+#    #+#             */
/*   Updated: 2022/02/04 15:07:37 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
			if (ft_strncmp_ps(instruction, "sa\n") == 0)
				ft_s(a);
			else if (ft_strncmp_ps(instruction, "sb\n") == 0)
				ft_s(&b);
			else if (ft_strncmp_ps(instruction, "ss\n") == 0)
			{
				ft_s(a);
				ft_s(&b);
			}
			else if (ft_strncmp_ps(instruction, "pa\n") == 0)
				ft_p(&b, a);
			else if (ft_strncmp_ps(instruction, "pb\n") == 0)
				ft_p(a, &b);
			else if (ft_strncmp_ps(instruction, "ra\n") == 0)
				ft_r(a);
			else if (ft_strncmp_ps(instruction, "rb\n") == 0)
				ft_r(&b);
			else if (ft_strncmp_ps(instruction, "rr\n") == 0)
			{
				ft_r(a);
				ft_r(&b);
			}
			else if (ft_strncmp_ps(instruction, "rra\n") == 0)
				ft_rr(a);
			else if (ft_strncmp_ps(instruction, "rrb\n") == 0)
				ft_rr(&b);
			else if (ft_strncmp_ps(instruction, "rrr\n") == 0)
			{
				ft_rr(a);
				ft_rr(&b);
			}						
		}
	}
}
