/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:21:24 by itkimura          #+#    #+#             */
/*   Updated: 2021/11/04 22:22:34 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)haystack;
	if (!*needle)
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] == needle[j])
		{
			if (!needle[j + 1])
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
