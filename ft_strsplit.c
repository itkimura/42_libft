/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:59:30 by itkimura          #+#    #+#             */
/*   Updated: 2021/11/23 16:52:42 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_array(char const *s, char c)
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

int	array_len(char const *s, char **str, char c, int array)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	str[array] = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
	{
		while (str[array])
		{
			free(str[array]);
			str[array] = 0;
			array--;
		}
		free(str);
		str = 0;
		return (0);
	}
	else
		return (1);
}

char	**fill_array(char **str, char const *s, char c)
{
	int	array;
	int	i;

	array = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			i = -1;
			if (!array_len(s, str, c, array))
				return (0);
			while (s[++i] != c)
				str[array][i] = s[i];
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
	char	**str;

	if (!s)
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
