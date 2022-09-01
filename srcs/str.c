/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:37:47 by itkimura          #+#    #+#             */
/*   Updated: 2022/04/04 12:38:54 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_c(t_format *f, va_list *ap, void (*p_flag[])(t_format *, char))
{
	unsigned char	c;

	c = 0;
	if (f->type == TYPE_C)
		c = (unsigned char)va_arg(*ap, int);
	if (f->type == TYPE_PER)
		c = '%';
	f->args_len = 1;
	if (f->args_len < f->width)
		f->space = f->width - f->args_len;
	if (f->flag == ZERO)
	{
		f->zero = f->space;
		f->space = 0;
	}
	p_flag[f->flag](f, c);
}

void	print_s(t_format *f, char *s, void (*p_flag[])(t_format *, char))
{
	if (f->precision == DOT_ONLY)
		f->precision = 0;
	else
		f->args_len = ft_strlen(s);
	if (f->precision < f->args_len && f->precision >= 0)
		f->args_len = f->precision;
	if (f->args_len < f->width)
		f->space = f->width - f->args_len;
	if (f->flag == ZERO)
	{
		f->zero = f->space;
		f->space = 0;
	}
	if (f->args_len == 0)
		p_flag[f->flag](f, 0);
	while (f->args_len)
	{
		p_flag[f->flag](f, *s);
		s++;
	}
}

void	put_s(t_format *f, va_list *ap, void (*p_flag[])(t_format *, char))
{
	char		*s;

	s = (char *)va_arg(*ap, char *);
	if (s == 0)
		s = "(null)";
	print_s(f, s, p_flag);
}
