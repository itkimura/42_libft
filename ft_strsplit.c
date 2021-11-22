/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:59:30 by itkimura          #+#    #+#             */
/*   Updated: 2021/11/22 20:28:49 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_array(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
				i++;
	}
	return (count);
}

int		array_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

char	**fill_array(char **str, char const *s, char c)
{
	int	array;
	int	len;
	int	i;

	array = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			len = array_len(s, c);
			str[array] = (char *)malloc(sizeof(char) * len + 1);
			if (!str)
				return (0);
			i = 0;
			while (s[i] != c)
			{
				str[array][i] = s[i];
				i++;
			}
			str[array][i] = '\0';
			array++;
		}
		while (*s != c && *s)
				s++;
	}
	str[array] = 0;
	return (str);
}

char	**ft_strsplit(char const *s, char c)
{
	char **str;

	if (!s || !c)
		return (0);
	str = (char **)malloc(sizeof(char *) * (count_array(s, c) + 1));
	if (!str)
		return (0);
	str = fill_array(str, s, c);
	if (!str)
		return (0);
	else
		return (str);
}
