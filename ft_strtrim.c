/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:31:25 by itkimura          #+#    #+#             */
/*   Updated: 2021/11/22 00:36:45 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	remove_space(char *s, int *begin, int *end)
{
	while (s[*begin] == ' ' || s[*begin] == '\n' || s[*begin] == '\t')
		*begin = *begin + 1;
	while (s[*end] == ' ' || s[*end] == '\n' || s[*end] == '\t')
		*end = *end - 1;
}
char *ft_strtrim(char const *s)
{
	char	*ret;
	int	i;
	int	len;
	int	begin;
	int	end;

	if (!s)
		return (0);
	begin = 0;
	end = ft_strlen(s) - 1;
	remove_space((char *)s, &begin, &end);
	len = (end - begin) + 2;
	if (len < 0)
		len = 1;
	ret = (char *)malloc(sizeof(char) * len);
	if (!ret)
		return (0);
	i = 0;
	while (begin <= end)
	{
		ret[i] = (char)s[begin];
		begin++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
