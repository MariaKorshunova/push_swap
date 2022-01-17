/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:25:07 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/17 17:17:30 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*median;
}	t_stack;

t_stack	*ft_create_node(void *content);

void	ft_push(t_stack **stack, t_stack *new);
void	ft_pop_stack(t_stack **stack);
void	ft_print_stack(t_stack *stack_a, t_stack *stack_b);
void	ft_s(t_stack **stack);
void	ft_p(t_stack **stack_src, t_stack **stack_dest, char c);
void	ft_r(t_stack **stack, char c);
void	ft_ra_rb(t_stack **a, t_stack **b);
void	ft_rr(t_stack **stack, char c);
void	ft_indexing_stack(t_stack **stack, int size);
void	ft_push_elem_to_b(t_stack **a, t_stack **b, int size, int size_median);

int		ft_create_stack(t_stack **stack_a, char *str);
int		ft_stacksize(t_stack *stack);
int		ft_atoi_check_digits(const char *str);
int		ft_duplicate_sort(t_stack *stack);

#endif