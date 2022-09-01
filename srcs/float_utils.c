/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:52:30 by itkimura          #+#    #+#             */
/*   Updated: 2022/04/04 15:49:20 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	array_add(int8_t *a, int8_t *b, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		a[i] += b[i];
		if (a[i] >= 10 && i != 0)
		{
			a[i] -= 10;
			a[i - 1] += 1;
		}
		i--;
	}
}

void	array_divbytwo(int8_t *n, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		n[i + 1] += (n[i] % 2) * 10;
		n[i] /= 2;
		i++;
	}
}

void	array_double(int8_t *n, int size)
{
	int		i;

	i = size - 1;
	while (i >= 0)
	{
		n[i] *= 2;
		if (i < size - 1 && n[i + 1] >= 10)
		{
			n[i] += 1;
			n[i + 1] -= 10;
		}
		i--;
	}
}
