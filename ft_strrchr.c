/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:54:27 by itkimura          #+#    #+#             */
/*   Updated: 2021/11/08 14:31:53 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	srclen;

	srclen = ft_strlen(s) - 1;
	while (s[srclen])
	{
		if(s[srclen] == c)
		{
			s += srclen;
			return ((char *)s);
		}
		srclen--;
	}
	return (0);
}
