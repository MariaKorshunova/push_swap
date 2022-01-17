# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 16:09:09 by jmabel            #+#    #+#              #
#    Updated: 2022/01/17 13:30:22 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= 	push_swap

HEADER				=	push_swap.h

SRCS_DIR_rules		=	./rules/
SRCS_DIR_sorting 	=	./sorting/
SRCS				=	push_swap.c\
						$(SRCS_DIR_rules)ft_stack.c			$(SRCS_DIR_rules)ft_check_error.c\
						$(SRCS_DIR_rules)ft_rules.c			$(SRCS_DIR_rules)ft_print_stack.c\
						$(SRCS_DIR_sorting)indexing.c		$(SRCS_DIR_sorting)sorting.c\

LIBFT				=	./libft/libft.a

OBJ 				= 	$(SRCS:%.c=%.o)

CC 					= 	cc 
CFLAGS 				= 	-Wall -Wextra -Werror

RM 					= 	rm -rf

all					:	$(NAME) 

%.o					: %.c $(HEADER) 
	$(CC) $(CFLAGS)  -c  $<  -o $@ 

$(NAME)				:	$(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME) 
	
$(LIBFT)			:
	make -C ./libft

.PHONY				:	all clean fclean re

clean:
	$(RM) $(OBJ)
	make clean -C ./libft

fclean				: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re					: fclean all