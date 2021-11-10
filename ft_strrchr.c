/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:54:27 by itkimura          #+#    #+#             */
/*   Updated: 2021/11/10 19:04:19 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	srclen;

	srclen = ft_strlen(s);
	while (srclen >= 0)
	{
		if(s[srclen] == c)
		return ((char *)&s[srclen]);
		srclen--;
	}
	return (0);
}
