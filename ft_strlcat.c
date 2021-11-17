/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:13:08 by itkimura          #+#    #+#             */
/*   Updated: 2021/11/17 15:52:15 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;

	if (ft_strlen(dst) >= dstsize)
		return (dstsize + ft_strlen(src));
	i = 0;
	dstlen = ft_strlen(dst);
	while (dstlen + 1 < dstsize && src[i])
	{
		dst[dstlen] = src[i];
		dstlen++;
		i++;
	}
	dst[dstlen] = '\0';
	return (dstlen - i + ft_strlen(src));
}
