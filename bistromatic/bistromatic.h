#ifndef BISTROMATIC_H

# define BISTROMATIC_H
# define PLUS +
# define MINUS -
# define MULT *
# define DIVIDE /
# define MODULO %
# define RPAREN )
# define LPAREN (

typedef struct s_stack
{
	char	data[1024];
	int	prec;
	struct	s_stack  *next;
}		t_stack;

# include "./libft/libft.h"
# include <stdio.h>
#endif
