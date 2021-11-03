/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:29:01 by itkimura          #+#    #+#             */
/*   Updated: 2021/11/03 18:22:22 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int	dstlen;
	int	i;

	i = 0;
	dstlen = ft_strlen(s1);
	while (s2[i])
		s1[dstlen++] = s2[i++];
	s1[dstlen + i] = '\0';
	return (s1);
}
