/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:54:30 by ckrommen          #+#    #+#             */
/*   Updated: 2018/01/09 12:54:33 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

char		*suppr_spaces(char *str)
{
	int		i;
	int		j;
	char	*str2;

	i = 0;
	j = 0;
	str2 = ft_strnew(ft_strlen(str));
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			str2[j] = str[i];
			j++;
		}
		i++;
	}
	ft_strdel(str);
	str2[j] = '\0';
	return (str2);
}

int			ft_parse_nbr(char **ps)
{
	int		nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	if ((*ps)[0] == PLUS || (*ps)[0] == MINUS)
	{
		if ((*ps)[0] == MINUS)
			sign = -1;
		*ps = *ps + 1;
	}
	if ((*ps)[0] == '(')
	{
		*ps = *ps + 1;
		nbr = handle_arith(ps);
		if ((*ps)[0] == ')')
			*ps = *ps + 1;
		return (sign * nbr);
	}
	while ('0' <= (*ps)[0] && (*ps)[0] <= '9')
	{
		nbr = (nbr * 10) + (*ps)[0] - '0';
		*ps = *ps + 1;
	}
	return (sign * nbr);
}

int			handle_arith(char **ps)
{
	int		lhs;
	int		rhs;
	char	op;

	lhs = ft_parse_nbr(ps);
	while ((*ps)[0] != '\0' && (*ps)[0] != RPAREN)
	{
		op = (*ps)[0];
		*ps = *ps + 1;
		if (op == PLUS || op == MINUS)
			rhs = handle_oper(ps);
		else
			rhs = ft_parse_nbr(ps);
		lhs = do_op(lhs, rhs, op);
	}
	return (lhs);
}

int			handle_oper(char **ps)
{
	int		lhs;
	int		rhs;
	char	op;

	lhs = ft_parse_nbr(ps);
	while ((*ps)[0] == MULT || (*ps)[0] == DIVIDE || (*ps)[0] == MODULO)
	{
		op = (*ps)[0];
		*ps = *ps + 1;
		rhs = ft_parse_nbr(ps);
		lhs = do_op(lhs, rhs, op);
	}
	return (lhs);
}

int			eval_expr(char *str)
{
	str = suppr_spaces(str);
	if (str[0] == '\0')
		return (0);
	return (handle_arith(&str));
}
