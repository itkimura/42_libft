/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:39:10 by itkimura          #+#    #+#             */
/*   Updated: 2022/04/04 19:07:15 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_intbit(t_float *data, uint64_t int_tmp)
{
	uint32_t	i;
	int8_t		n[53];
	uint64_t	bit;

	i = 0;
	ft_memset(n, 0, sizeof(n));
	n[53 - 1] = 1;
	bit = 1;
	while (i < 54)
	{
		if (int_tmp & bit)
			array_add(data->intpart, n, 53);
		array_double(n, 53);
		bit <<= 1;
		i++;
	}
	while (i++ <= data->exp - 1023)
		array_double(data->intpart, 53);
}

void	convert_intpart(t_float *data)
{
	int			offset;
	uint64_t	int_tmp;

	if (data->exp < 1023 || data->exp == 1021)
		return ;
	else if (data->exp < 1023 + 52)
		offset = data->exp - 1023;
	else
		offset = 53;
	if (offset == 0)
		int_tmp = 1;
	else
		int_tmp = (data->frac >> (64 - offset)) | (1L << offset);
	convert_intbit(data, int_tmp);
}

void	convert_fracbit(t_float *data, uint64_t frac_tmp, int8_t *n)
{
	uint32_t	i;
	uint64_t	bit;

	i = 0;
	bit = 1L << 63;
	while (i < 54)
	{
		if (frac_tmp & bit)
			array_add(data->fracpart, n, 1077);
		array_divbytwo(n, 1077);
		bit >>= 1;
		i++;
	}
}

void	convert_fracpart(t_float *data)
{
	uint64_t		frac_tmp;
	int8_t			n[1077];
	unsigned int	i;

	ft_memset(n, 0, sizeof(n));
	n[0] = 5;
	if (data->exp >= 53 + 1023 || (data->exp == 0 && data->frac == 0))
		return ;
	else if (data->exp >= 1023)
		frac_tmp = data->frac << (data->exp - 1023);
	else if (data->exp == 0)
		frac_tmp = data->frac;
	else
	{
		frac_tmp = data->frac >> 1 | (1L << 63);
		i = 0;
		while (i < (1022 - data->exp))
		{
			array_divbytwo(n, 1077);
			i++;
		}
	}
	convert_fracbit(data, frac_tmp, n);
}
