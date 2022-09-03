/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:50:52 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/01 12:13:17 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_floatstr(t_format *f, t_float *data,
		char *str, void (*p_flag[])(t_format *, char))
{
	int		len;
	int		i;

	len = f->args_len + 1;
	if (str[0] != '0')
	{
		i = 0;
		f->args_len++;
		len++;
		if (f->space)
			f->space--;
		else if (f->flag == ZERO && f->zero)
			f->zero--;
	}
	else
		i = 1;
	while (i < len)
	{
		p_flag[f->flag](f, str[i]);
		if (i == data->dot)
			p_flag[f->flag](f, '.');
		i++;
	}
}

void	print_f(t_format *f, t_float *data, void (*p_flag[])(t_format *, char))
{
	int			len;
	char		*str;
	int			i;

	if (f->args_len < 4)
		len = 4;
	else
		len = f->args_len + 1;
	str = ft_strnew(len);
	i = len;
	str[0] = '0';
	while (i >= 0)
	{
		if (i > data->dot)
		{
			str[i] = data->fracpart[i - (data->dot + 1)] + '0';
		}
		else
			str[i] = data->intpart[52 - (data->dot - i)] + '0';
		i--;
	}
	rounding(str, is_round(data));
	print_floatstr(f, data, str, p_flag);
	free(str);
}
