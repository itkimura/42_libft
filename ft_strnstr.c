/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:21:24 by itkimura          #+#    #+#             */
/*   Updated: 2021/11/03 16:40:39 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*s1;
	char	*s2;

	if (!(*needle))
		return ((char *)haystack);
	while (*haystack && len)
	{
		s1 = (char *)haystack;
		s2 = (char *)needle;
		while (*s1 && !(*s1 - *s2))
		{
			s1++;
			s2++;
			if (!*s2)
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (0);
}
