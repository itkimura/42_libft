/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_rounding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:39:10 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/01 12:12:41 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	remaining(t_float *data, int start)
{
	int	i;
	int	res;

	res = 0;
	i = start + 1;
	while (data->fracpart[i] == 0 && i < 1077)
		i++;
	if (i == 1077)
		res = 2;
	else
		res = 1;
	return (res);
}

int	is_round(t_float *data)
{
	int		res;
	int		start;

	res = 0;
	if (data->frac_len == 0)
		start = 0;
	else
		start = data->frac_len - 1;
	if (data->fracpart[start] > 5)
		return (1);
	if (data->fracpart[start] == 4)
	{
		if (data->fracpart[start + 1] > 5)
			return (remaining(data, start));
		if (data->fracpart[start + 1] < 5)
			return (0);
	}
	if (data->fracpart[start] == 5)
		return (remaining(data, start));
	return (res);
}

void	round_check(int i, char *str, int *flag)
{
	int	j;

	if (str[i + 1] == '9' && str[i] != '9')
	{
		j = i + 1;
		while (str[j] == '9')
			str[j++] = '0';
		*flag = 0;
	}
	if (str[i] != '9')
	{
		str[i]++;
		*flag = 0;
	}
}

void	rounding(char *str, int round)
{
	int	i;
	int	flag;

	i = ft_strlen(str) - 1;
	flag = 1;
	while (i >= 0)
	{
		if ((str[i + 1] >= '5') && flag
			&& ((round == 2 && ((str[i] - '0') % 2) == 1) || (round == 1)))
			round_check(i, str, &flag);
		if (str[i + 1] >= '5' && round == 2 && ((str[i] - '0') % 2) == 0)
			break ;
		i--;
	}
}
