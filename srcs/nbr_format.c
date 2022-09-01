/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_fromat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:42:48 by itkimura          #+#    #+#             */
/*   Updated: 2022/04/04 19:00:39 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_sharp(t_format *f, unsigned long long nb)
{
	if ((f->type == TYPE_SX && nb != 0) || f->type == TYPE_P)
	{
		f->prefix = "0x";
		f->sharp = 2;
	}
	else if (f->type == TYPE_LX && nb != 0)
	{
		f->prefix = "0X";
		f->sharp = 2;
	}
	else if (f->type == TYPE_O)
	{
		if (nb != 0)
			f->prefix = "0";
		f->sharp = 1;
	}
	else
		f->sharp = 0;
}

void	set_base(t_format *f, unsigned long long nb)
{
	if (f->type == TYPE_O)
		f->base = 8;
	if (f->type == TYPE_D || f->type == TYPE_I || f->type == TYPE_U)
		f->base = 10;
	if (f->type == TYPE_SX || f->type == TYPE_LX || f->type == TYPE_P)
		f->base = 16;
	if (f->type == TYPE_SX || f->type == TYPE_P)
		f->basestr = "0123456789abcdef";
	if (f->sharp || f->type == TYPE_P)
		set_sharp(f, nb);
}

void	set_nbrlen(t_format *f, unsigned long long nb)
{
	if (f->type == TYPE_O && f->sharp && nb == 0)
		f->args_len = 1;
	else if (f->precision == -1 && nb == 0)
		f->args_len = 1;
	else
		f->args_len = get_digits(nb, f->base);
	if (f->args_len < f->precision)
		f->zero = f->precision - f->args_len;
}

void	set_nbrformat(t_format *f, unsigned long long nb)
{
	set_nbrlen(f, nb);
	if (f->args_len + f->zero < f->width)
	{
		f->space = f->width - f->args_len - f->zero - f->sign - f->sharp;
		if (f->flag == ZERO && f->zero == 0
			&& (f->precision == -1 || f->precision == INVALID))
		{
			f->zero = f->space - f->space_flag;
			f->space = 0;
		}
	}
	if ((f->type == TYPE_D || f->type == TYPE_I) && f->space_flag && !f->sign)
	{
		f->prefix = " ";
		if (f->space != 0)
			f->space--;
	}
	if (f->sharp && f->type == TYPE_O && f->zero && f->precision > 0 && nb != 0)
		f->zero--;
}
