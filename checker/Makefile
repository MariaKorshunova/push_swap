# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 16:09:09 by jmabel            #+#    #+#              #
#    Updated: 2022/02/03 20:51:25 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= 	checker

HEADER				=	checker.h
HEADER_GNL			=	../get_next_line/get_next_line.h

SRCS_DIR_GNL		=	../get_next_line/

SRCS				=	checker.c	stack_checker.c	ft_check_error_checker.c\
						$(SRCS_DIR_GNL)get_next_line.c	$(SRCS_DIR_GNL)get_next_line_utils.c\
						ft_print_stack.c\

LIBFT				=	../libft/libft.a

OBJ 				= 	$(SRCS:%.c=%.o)

CC 					= 	cc 
CFLAGS 				= 	-Wall -Wextra -Werror

RM 					= 	rm -rf

all					:	$(NAME) 

%.o					: %.c $(HEADER) $(HEADER_GNL)
	$(CC) $(CFLAGS)  -c  $<  -o $@ 

$(NAME)				:	$(OBJ) $(LIBFT)
	$(CC) $(OBJ) -L ../libft -lft -o $(NAME)
	
$(LIBFT)			:
	make -C ../libft

.PHONY				:	all clean fclean re

clean:
	$(RM) $(OBJ)
	make clean -C ../libft

fclean				: clean
	$(RM) $(NAME)
	make fclean -C ../libft

re					: fclean all
