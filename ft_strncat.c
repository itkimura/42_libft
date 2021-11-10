/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:29:01 by itkimura          #+#    #+#             */
/*   Updated: 2021/11/10 19:43:10 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int	dstlen;
	size_t	i;

	i = 0;
	dstlen = ft_strlen(s1);
	while (i < n && s2[i])
	{
		s1[dstlen + i] = s2[i];
		i++;
	}
	s1[dstlen + i] = '\0';
	return (s1);
}
