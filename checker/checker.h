/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:18:33 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/30 22:16:13 by jmabel           ###   ########.fr       */
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

int		ft_create_stack(t_stack **stack_a, char *str, char **intsruction);
int		ft_atoi_checker(const char *str, int *flag_error);

void	ft_push(t_stack **stack, t_stack *new);
void	ft_pop_stack(t_stack **stack);

#endif
