/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:21:24 by itkimura          #+#    #+#             */
/*   Updated: 2021/11/07 17:40:18 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)haystack;
	if (!(*needle))
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == needle[j] && str[i + j] && (i + j) < len)
		{
			if (!(needle[j + 1]))
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
