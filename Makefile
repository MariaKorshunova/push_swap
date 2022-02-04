# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 16:09:09 by jmabel            #+#    #+#              #
#    Updated: 2022/02/04 20:03:29 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= 	push_swap
NAME_CHECKER		=	checker

SRCS_DIR_rules		=	./rules/
SRCS_DIR_sorting 	=	./sorting/
SRCS_DIR_checker	=	./checker_dir/
SRCS_DIR_GNL		=	./get_next_line/

HEADER				=	push_swap.h
HEADER_GNL			=	$(SRCS_DIR_GNL)get_next_line.h


SRCS				=	push_swap.c\
						$(SRCS_DIR_rules)ft_stack.c					$(SRCS_DIR_rules)ft_check_error.c\
						$(SRCS_DIR_rules)ft_rules_s_p.c				$(SRCS_DIR_rules)ft_rules_rr.c\
						$(SRCS_DIR_rules)ft_stack_utils.c			$(SRCS_DIR_rules)ft_print_stack.c\
						$(SRCS_DIR_sorting)indexing.c				$(SRCS_DIR_sorting)push_to_b.c\
						$(SRCS_DIR_sorting)count_return.c			$(SRCS_DIR_sorting)push_to_a.c\
						$(SRCS_DIR_sorting)scenario.c				$(SRCS_DIR_sorting)sorting.c\

SRCS_CHECKER	=		$(SRCS_DIR_checker)checker.c				$(SRCS_DIR_checker)parser.c\
						$(SRCS_DIR_GNL)get_next_line.c				$(SRCS_DIR_GNL)get_next_line_utils.c\
						$(SRCS_DIR_rules)ft_stack.c					$(SRCS_DIR_rules)ft_check_error.c\

LIBFT				=	./libft/libft.a

OBJ 				= 	$(SRCS:%.c=%.o)
OBJ_CHECKER 		= 	$(SRCS_CHECKER:%.c=%.o)

CC 					= 	cc 
CFLAGS 				= 	-Wall -Wextra -Werror

RM 					= 	rm -rf

all					:	$(NAME) 

$(NAME)				:	$(OBJ) $(LIBFT)
	$(CC) $(OBJ) -L ./libft -lft -o $(NAME)

bonus				:	$(NAME_CHECKER)

$(NAME_CHECKER)		:	$(OBJ_CHECKER) $(LIBFT)
	$(CC) $(OBJ_CHECKER) -L ./libft -lft -o $(NAME_CHECKER)

$(LIBFT)			:
	make -C ./libft

%.o					: %.c $(HEADER) $(HEADER_GNL)
	$(CC) $(CFLAGS)  -c  $<  -o $@ 


.PHONY				:	all clean fclean re bonus

clean:
	$(RM) $(OBJ) $(OBJ_CHECKER)
	make clean -C ./libft

fclean				: clean
	$(RM) $(NAME) $(NAME_CHECKER)
	make fclean -C ./libft

re					: fclean all
