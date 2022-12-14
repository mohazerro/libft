/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohazerr <mohazerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:57:51 by mohazerr          #+#    #+#             */
/*   Updated: 2022/09/21 00:50:18 by mohazerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*headlist;

	if (lst == NULL)
		return (NULL);
	newlist = ft_lstnew((*f)(lst->content));
	if (!newlist)
		return (NULL);
	headlist = newlist;
	lst = lst->next;
	while (lst != NULL)
	{
		newlist->next = ft_lstnew((*f)(lst->content));
		if (!newlist->next)
		{
			ft_lstclear(&headlist, del);
			return (NULL);
		}
		newlist = newlist->next;
		lst = lst->next;
	}
	return (headlist);
}
