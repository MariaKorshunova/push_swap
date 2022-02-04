/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:18:33 by jmabel            #+#    #+#             */
/*   Updated: 2022/02/04 14:12:12 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_create_node(void *content);

void	ft_create_stack(t_stack **a, char *str);
void	ft_push(t_stack **stack, t_stack *new);
void	ft_pop_stack(t_stack **stack);
void	ft_parser(t_stack **a);
void	ft_s(t_stack **stack);
void	ft_p(t_stack **stack_src, t_stack **stack_dest);
void	ft_r(t_stack **stack);
void	ft_rr(t_stack **stack);

int		ft_atoi_check_digits(const char *str);
int		ft_duplicate_sort(t_stack *stack);

void	ft_print_stack(t_stack *stack_a, t_stack *stack_b);

#endif
