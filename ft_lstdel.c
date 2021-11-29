/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:26:07 by itkimura          #+#    #+#             */
/*   Updated: 2021/11/29 16:20:54 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*tmp;

	next = *alst;
	tmp = *alst;
	while (next)
	{
		next = (*alst)->next;
		ft_lstdelone(&*alst, del);
		*alst = next;
	}
	*alst = tmp;
	*alst = NULL;
}
