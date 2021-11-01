/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:27:13 by itkimura          #+#    #+#             */
/*   Updated: 2021/11/01 16:58:15 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

const char	*ft_isspace(const char *str, int *flag)
{
	*flag = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*flag = *flag * -1;
		str++;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int	flag;
	int	dest;

	dest = 0;
	str = ft_isspace(str, &flag);
	if(*str >= '0' && *str <= '9')
	{
		while (*str >= '0' && *str <= '9')
		{
			dest = (dest * 10) + (*str - '0');
			str++;
		}
		return (dest * flag);
	}
	else
		return (0);
}
