#include "bistromatic.h"

int bra_char(char c)
{
    if (c == LPAREN)
        return (1);
    else if (c == RPAREN)
        return (-1);
    else
        return (0);
}

int check_brackets(char *format)
{
    double	total;

    total = 1.0;
    while (*format)
    {
        if (bra_char(*format) > 0)
            total = (total * 10) + bra_char(*format);
        else if (bra_char(*format) < 0)
            total = ((total + bra_char(*format)) / 10);
        if (total < 0)
            break ;
        format++;
    }
    return (total);
}

t_stack	*create_elem(char *data)
{
  t_stack *elem;
  int i;

  elem = (t_stack *)malloc(sizeof(t_stack));
  ft_bzero(elem->data, 1024);
  elem->prec = 0;
  i = 0;
  while (*data)
  {
      elem->data[i] = *data;
      data++;
      i++;
  }
  elem->next = NULL;
  return (elem);
}

void	push(t_stack *stack, t_stack *elem)
{
  t_stack	*ptr;

  ptr = stack;
  while (ptr->next)
    ptr = ptr->next;
  ptr->next = elem;
}

t_stack *pop(t_stack *stack)
{
  t_stack	*ptr;
  t_stack	*elem;

  ptr = stack;
  while (ptr->next->next)
    ptr = ptr->next;
  elem = ptr->next;
  ptr->next = NULL;
  return (elem);
}

void	handle_value(char *str, int i, t_stack *val)
{
  char data[1024];

  while (isnum(str[i]) && str[i])
    {
      *data = str[i];
      data++;
      i++;
    }
  push(val, create_elem(data));
  return (i);
}

int	do_op(char *p1, char *p2, char oper)
{
  int x;
  int y;

  x = ft_atoi(p1);
  y = ft_atoi(p2);
  if (oper == PLUS)
    return (x + y);
  else if (oper == MINUS)
    return (x - y);
  else if (oper == MULT)
    return (x * y);
  else if (oper == DIVIDE)
    return (x / y);
  else if (oper == MODULO)
    return (x % y);
  else
    return (-1);
}

void	handle_rparen(t_stack *op, t_stack *val)
{
  t_stack	*p1;
  t_stack	*p2;
  t_stack	*oper;
  int		res;
  char		*mem;

  while (op->data[0] != LPAREN)
    {
      oper = pop(op);
      p1 = pop(val);
      p2 = pop(val);
      res = do_op(p1->data, p2->data, *oper->data);
      free(p1);
      free(p2);
      free(oper);
      mem = ft_itoa(res);
      push(val, create_elem(mem));
      ft_strdel(mem);
    }
  if (op->data)
}

int	expr_parse(char *str, t_stack *op, t_stack *val)
{
  //  char str[1024];
  int i;

  i = 0;
  while (str[i])
    {
      ft_bzero(buf, 1024);
      if (ft_isnum(str[i]))
	i = handle_value(str, i, val);
      else if (str[i] == LPAREN)
	push(op, x)
      else if (str[i] == '32')
	 ;
      else if (str[i] == RPAREN)
	handle_rparen(op, val);
      else if (str[i] == PLUS || str[i] == MINUS || str[i] == MODULO ||
	       str[i] == MULT || str[i] == DIVIDE)
	handle_op(str, i , );
      else
	return (-1);
    }
}

void	calc(char *av1, char *av2)
{
  t_stack *op;
  t_stack *val;
  int		res;

  op = create_elem("start");
  val = create_elem("start");
  res = expr_parse(av1, op, val);
}

int main(int argc, char **argv)
{
    if (argc != 3)
        ft_putendl("usage: ./calc base input_size");
    else
        calc(argv[1], argv[2]);
}
