#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 12:59:02 by ckrommen          #+#    #+#              #
#    Updated: 2018/01/09 13:42:53 by ckrommen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -Wall -Wextra -Werror

RM	= rm -f

LIBFT = libft

NAME = calc

HEADER = bistromatic.h

SRCS = eval_expr.c do_op.c calc.c $(LIBFT)/libft.a

OBJS = eval_expr.o do_op.o calc.o

$(NAME):
	@echo "Compiling Libft"
	@make -C $(LIBFT) re
	@echo "Compiling Main files"
	@gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HEADER)

all: $(NAME)

clean:
	@echo "Cleaning up"
	@make -C $(LIBFT) clean

fclean: clean
	@echo "Full clean"
	@make -C $(LIBFT) fclean
	@$(RM) $(NAME)

re: fclean all