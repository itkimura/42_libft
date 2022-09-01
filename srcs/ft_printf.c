/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:29:48 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/01 12:11:55 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_format(t_format *f)
{
	int	i;

	f->flag = NONE;
	f->width = INIT;
	f->type = INIT;
	f->precision = INIT;
	f->args_len = 0;
	f->zero = 0;
	f->space = 0;
	f->base = 0;
	f->res = 0;
	f->space_flag = 0;
	f->sign = 0;
	f->sharp = 0;
	f->prefix = "";
	f->basestr = "0123456789ABCDEF";
	i = 0;
	while (i < 9)
		f->length[i++] = 0;
}

int	get_digits(unsigned long long nb, int base)
{
	int	digits;

	digits = 0;
	while (nb)
	{
		digits++;
		nb /= base;
	}
	return (digits);
}

void	put_flag(t_format *f, char **itr)
{
	while (**itr == '0' || **itr == '-' || **itr == '+'
		|| **itr == '#' || **itr == ' ')
	{
		if (**itr == '0' && f->flag != MINUS)
			f->flag = ZERO;
		if (**itr == '-')
			f->flag = MINUS;
		if (**itr == '+')
			f->sign = 1;
		if (**itr == '#')
			f->sharp = 1;
		if (**itr == ' ' && f->sign == 0)
			f->space_flag = 1;
		(*itr)++;
	}
}

int	read_percentage(t_format *f, char **itr, va_list *ap)
{
	initialize_format(f);
	put_flag(f, itr);
	put_width(itr, f, ap);
	if (**itr == '.')
		put_precision(itr, f, ap);
	put_length(itr, f);
	f->type = is_specifier(itr, TYPE);
	if (f->type == -1)
		return (0);
	else
		(*itr)++;
	print_format(f, ap);
	return (f->res);
}

/*
 * va_start and va_end
 * A function may be called with a varying number of arguments of varying types
 * va_start -> initializes ap
 * va_args -> for each agument to be processed
 * va_end -> signals that there are no further arguments
*/

int	ft_printf(const char *format, ...)
{
	char		*itr;
	int			res;
	va_list		ap;
	t_format	f;

	itr = (char *)format;
	if (!itr)
		return (0);
	res = 0;
	va_start(ap, format);
	while (*itr)
	{
		if (*itr == '%' && *++itr != '%')
		{
			res += read_percentage(&f, &itr, &ap);
			continue ;
		}
		res += int_putchar(*itr);
		itr++;
	}
	va_end(ap);
	return (res);
}
