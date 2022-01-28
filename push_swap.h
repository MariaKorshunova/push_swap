/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:25:07 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/27 18:35:10 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	int				number;
	struct s_stack	*next;
	struct s_stack	*min;
	struct s_stack	*max;
	struct s_stack	*median;
	struct s_steps	*steps;
}	t_stack;

typedef struct s_steps
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	size_a;
	int	size_b;
	int	scenario;
}	t_steps;

t_stack	*ft_create_node(void *content);
t_steps	*ft_node_steps(int size_a, int size_b);

void	ft_qsort_stack(t_stack **a, t_stack **b, int size);
// void	ft_index_sort(t_stack **a, t_stack **b, int size);
void	ft_push(t_stack **stack, t_stack *new);
void	ft_pop_stack(t_stack **stack);
void	ft_s(t_stack **stack, char c);
void	ft_p(t_stack **stack_src, t_stack **stack_dest, char c);
void	ft_r(t_stack **stack, char c);
void	ft_rr(t_stack **stack, char c);
void	ft_indexing_stack(t_stack **stack, int size);
void	ft_serial_number(t_stack *s); // порядковый номер в стеке
void	ft_push_elem_to_b(t_stack **a, t_stack **b, int size);
void	ft_count_operations(t_stack *a, t_stack *b);
void	ft_push_elem_to_a(t_stack **a, t_stack **b);
void	ft_scenario_rbrra(t_stack **a, t_stack **b, t_stack *elem);
void	ft_scenario_rarrb(t_stack **a, t_stack **b, t_stack *elem);
void	ft_scenario_rr(t_stack **a, t_stack **b, t_stack *elem);
void	ft_scenario_rrr(t_stack **a, t_stack **b, t_stack *elem);
void	ft_search_min_max(t_stack *stack, t_stack **min, t_stack **max);
void	ft_min_to_top(t_stack **a, int size);
void	ft_sort_three(t_stack **s, char c);
// void	ft_define_steps_index(t_stack *a, t_stack *b, t_stack *pos);

int		ft_create_stack(t_stack **stack_a, char *str);
int		ft_stacksize(t_stack *stack);
int		ft_atoi_check_digits(const char *str);
int		ft_duplicate_sort(t_stack *stack);
int		ft_ra_rb(t_stack **a, t_stack **b);
int		ft_rra_rrb(t_stack **a, t_stack **b);

void	ft_print_stack(t_stack *stack_a, t_stack *stack_b);
void	ft_print_steps(t_stack *s);

#endif