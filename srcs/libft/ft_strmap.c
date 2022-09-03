/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:53:45 by itkimura          #+#    #+#             */
/*   Updated: 2021/11/21 01:20:43 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	int		i;

	i = 0;
	if (!s)
		return (0);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dst)
		return (0);
	while (s[i])
	{
		dst[i] = f(s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
