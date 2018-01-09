/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:35:22 by ckrommen          #+#    #+#             */
/*   Updated: 2018/01/09 13:35:24 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

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
