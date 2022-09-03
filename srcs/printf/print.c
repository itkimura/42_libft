/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:27:29 by itkimura          #+#    #+#             */
/*   Updated: 2022/04/04 16:01:32 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_putchar(char c)
{
	return (write(1, &c, 1));
}

void	flag_none(t_format *f, char c)
{
	while (f->space)
	{
		f->res += int_putchar(' ');
		f->space--;
	}
	while (*(f->prefix) && f->type != TYPE_S)
	{
		f->res += int_putchar(*f->prefix);
		f->prefix++;
	}
	while (f->zero)
	{
		f->res += int_putchar('0');
		f->zero--;
	}
	if (f->args_len)
	{
		f->res += int_putchar(c);
		f->args_len--;
	}
}

void	flag_minus(t_format *f, char c)
{
	while (*(f->prefix))
	{
		f->res += int_putchar(*f->prefix);
		f->prefix++;
	}
	while (f->zero)
	{
		f->res += int_putchar('0');
		f->zero--;
	}
	if (f->args_len)
	{
		f->res += int_putchar(c);
		f->args_len--;
	}
	while (f->space && !f->args_len)
	{
		f->res += int_putchar(' ');
		f->space--;
	}
}
