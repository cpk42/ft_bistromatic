/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 14:13:13 by kvandenb          #+#    #+#             */
/*   Updated: 2017/07/16 14:13:15 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	do_op(int lhs, int rhs, char op)
{
	if (op == '+')
		return (lhs + rhs);
	else if (op == '-')
		return (lhs - rhs);
	else if (op == '*')
		return (lhs * rhs);
	else if (op == '/')
		return (lhs / rhs);
	else if (op == '%')
		return (lhs % rhs);
	else
		return (0);
}
