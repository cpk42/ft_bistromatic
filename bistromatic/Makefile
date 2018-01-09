#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 12:59:02 by ckrommen          #+#    #+#              #
#    Updated: 2018/01/09 13:23:40 by ckrommen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -Wall -Wextra -Werror

RM	= rm -f

LIBFT = libft

NAME = calc

HEADER = ft_list.h

SRCS = eval_expr.c do_op.c calc.c $(LIBFT)/libft.a

OBJS = eval_expr.o do_op.o calc.o

$(NAME):
	@make -C $(LIBFT) re
	@gcc $(FLAGS) -c $(SRCS)
	@gcc $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	@make -C $(LIBFT) clean
	@$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT) fclean
	@$(RM) $(NAME)

re: fclean all