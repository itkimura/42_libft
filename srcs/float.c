/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:39:10 by itkimura          #+#    #+#             */
/*   Updated: 2022/04/05 12:52:07 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	float_initialize(t_float *data)
{
	data->dot = 0;
	data->frac_len = 0;
	data->sign = 0;
	data->exp = 0;
	data->frac = 0;
	ft_memset(data->intpart, 0, sizeof(data->intpart));
	ft_memset(data->fracpart, 0, sizeof(data->fracpart));
}

int	is_longmax(uint64_t tmp)
{
	uint64_t	bit;
	int			i;

	i = 0;
	bit = 1L << 63;
	while (bit != 0)
	{
		if (tmp & bit)
			i++;
		else
			break ;
		bit >>= 1;
	}
	if (i == 64)
		return (1);
	else
		return (0);
}

void	get_float(t_format *f, t_float *data, va_list *ap, uint64_t *tmp)
{
	double			nb;
	long double		longnb;

	nb = 0;
	if (f->length[L])
	{
		longnb = va_arg(*ap, long double);
		nb = (double)longnb;
	}
	else
		nb = va_arg(*ap, double);
	ft_memcpy(tmp, &nb, sizeof(uint64_t));
	data->sign = *tmp >> 63;
	data->exp = *tmp >> 52;
	data->frac = *tmp << 12;
}

void	put_f(t_format *f, va_list *ap, void (*p_flag[])(t_format *, char))
{
	t_float		data;
	uint64_t	tmp;

	tmp = 0;
	float_initialize(&data);
	get_float(f, &data, ap, &tmp);
	if (is_longmax(tmp))
		print_s(f, "nan", p_flag);
	else if (data.exp == 2047 && data.frac == 0)
	{
		if (f->flag == ZERO)
			f->flag = NONE;
		print_s(f, "inf", p_flag);
	}
	else
	{
		if (data.sign == 1)
			data.exp = data.exp ^ (1 << 11);
		convert_intpart(&data);
		convert_fracpart(&data);
		float_format(f, &data);
		print_f(f, &data, p_flag);
	}
}
