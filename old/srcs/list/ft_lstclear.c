/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohazerr <mohazerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 04:28:15 by mohazerr          #+#    #+#             */
/*   Updated: 2022/09/20 04:43:22 by mohazerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*cplst;

	if (lst == NULL || del == NULL)
		return ;
	cplst = *(lst);
	while (cplst != NULL)
	{
		(*del)(cplst->content);
		temp = cplst->next;
		free(cplst);
		cplst = temp;
	}
	*lst = NULL;
}
