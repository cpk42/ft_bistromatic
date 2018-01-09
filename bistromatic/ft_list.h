/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatic.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:40:54 by ckrommen          #+#    #+#             */
/*   Updated: 2018/01/09 12:45:59 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTROMATIC_H
# define BISTROMATIC_H

# define PLUS +
# define MINUS -
# define MULT *
# define DIVIDE /
# define MODULO %
# define RPAREN )
# define LPAREN (

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int		do_op(int lhs, int rhs, char op);
char	*suppr_spaces(char *str);
int		ft_parse_nbr(char **ps);
int		eval_expr_0(char **ps);
int		eval_expr_1(char **ps);
int		eval_expr(char *str);

#endif
