/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:59:30 by itkimura          #+#    #+#             */
/*   Updated: 2022/02/09 16:06:58 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static char	**free_array(char **str, int array)
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

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		words;
	int		len;
	int		array;

	if (!s)
		return (0);
	words = count_words(s, c);
	str = (char **)malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (0);
	array = 0;
	while (array < words && str)
	{
		while (*s && *s == c)
			s++;
		len = word_len(s, c);
		str[array] = ft_strsub(s, 0, len);
		if (!str[array])
			return (free_array(str, array));
		s += len;
		array++;
	}
	str[array] = 0;
	return (str);
}
