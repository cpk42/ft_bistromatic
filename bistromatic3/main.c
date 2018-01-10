/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:00:02 by lhernand          #+#    #+#             */
/*   Updated: 2018/01/09 21:39:55 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct 			s_stack
{
	char 				num;
	char				op;
	int					sign;
	int					carry;
	struct s_stack		*next;
}						t_stack;

void					print_usage(int exit_code)
{
	ft_putstr("Usage: ./calc base buf_size");
	exit(exit_code);
}

t_stack					*create_elem(char n, char op, int sign, int carry)
{
	t_stack	*head;

	head = (t_stack *)malloc(sizeof(t_stack));
	head->num = n;
	head->op = op;
	head->sign = sign;
	head->carry = carry;
	head->next = NULL;
	return (head);
}

int						is_operand(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (1);
	return (0);
}

void					push(t_stack **list, char n, char op, int sign, int c)
{
	t_stack *node;

	if (*list)
	{
		node = list;
		while (node->next)
			node = node->next;
		if (is_operand(op))
			create(NULL, op, sign, c);
		else
			create(n, NULL, sign, c);
	}
	else
	{
		if (is_operand(op))
			*list = create(NULL, op, sign, c);
		else
			*list = create(n, NULL, sign, c);
	}
}

void					print(t_stack **list)
{
	t_stack *node;

	node = *list;
	while (node->next)
	{
		ft_putchar(n);
		ft_putchar('\n');
		ft_putchar(op);
		ft_putchar('\n');
		ft_putnbr(sign);
		ft_putchar('\n');
		ft_putnbr(c);
		ft_putchar('\n');
	}
}

/*
void					calc(char *buff, int buff_size)
{
	

}
*/
int						main(int argc, char **argv)
{
	int ret;
	char *buff;
	char *list; 
	int  i;

	i = 0;
	list = NULL;
	if (argc != 3)
		print_usage(1);
	else
	{
		buff = ft_strnew(ft_atoi(argv[2]));
		ret = read(0, buff, ft_atoi(argv[2]));
		if (ret != 0)
		{
			ft_putstr(buff);
			while (i < ft_atoi(argv[2]))
			{
				push(&list, buff[i], buff[i], 1, 1);
				i++;
			}
			print(&list);
		}
		else
			exit(2);		
	}
	return (0);
}
