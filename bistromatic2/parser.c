/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:58:57 by lhernand          #+#    #+#             */
/*   Updated: 2018/01/09 13:58:52 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistro.h"
#include <fcntl.h>

//#include  <fcntl.h>
//	int  read(  int  handle,  void  *buffer,  int  nbyte );


void		print_usage(int exit_code)
{
	ft_putstr("Usage: ./calc base input_base");
	exit(exit_code);
}


int			main(int argc, char **argv)
{	

	//char *str;
	char *buffer;
	int ret;

	if (argc != 3)
		print_usage(1);
	else
	{	
			buffer = ft_strnew(ft_atoi(argv[2]));
			(ret = read(0, buffer, ft_atoi(argv[2])));
			if (ret != 0)
				ft_putstr(buffer); 
	}
	return (0);
}
