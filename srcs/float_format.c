/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:39:10 by itkimura          #+#    #+#             */
/*   Updated: 2022/04/04 22:18:36 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	float_flag(t_format *f, t_float *data)
{
	if (data->sign == 1)
	{
		f->prefix = "-";
		f->sign = 1;
		f->space_flag = 0;
	}
	if (f->sign == 1 && data->sign == 0)
		f->prefix = "+";
}

void	float_len(t_format *f, t_float *data)
{
	while (data->intpart[data->dot] == 0 && data->dot < 53)
		data->dot++;
	if (data->dot == 53)
		data->dot = 1;
	else
		data->dot = 53 - data->dot;
	if (f->precision == INIT || f->precision == INVALID)
		data->frac_len = 7;
	else if (f->precision != 0 && f->precision != DOT_ONLY)
		data->frac_len = f->precision + 1;
	else if ((f->precision == DOT_ONLY || f->precision == 0) && f->sharp)
		data->frac_len = 1;
	else
		data->frac_len = 0;
}

void	float_format(t_format *f, t_float *data)
{
	float_len(f, data);
	float_flag(f, data);
	f->args_len = data->dot + data->frac_len;
	if (f->args_len < f->width)
	{
		f->space = f->width - f->args_len - f->zero - f->sign;
		if (f->flag == ZERO)
		{
			f->zero = f->space - f->space_flag;
			f->space = 0;
		}
	}
	if (f->space_flag && f->space == 0 && f->sign == 0)
		f->space++;
}
