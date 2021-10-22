/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:11:27 by rbell             #+#    #+#             */
/*   Updated: 2021/10/11 13:11:29 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr_new;
	t_list	*begin_new;

	if (NULL == lst)
		return (NULL);
	begin_new = NULL;
	while (lst)
	{
		curr_new = ft_lstnew(f(lst->content));
		if (NULL == curr_new && begin_new)
		{
			ft_lstclear(&begin_new, del);
			return (NULL);
		}
		else if (NULL == curr_new)
			return (NULL);
		if (!begin_new)
		{
			begin_new = curr_new;
			begin_new->next = NULL;
		}
		ft_lstadd_back(&begin_new, curr_new);
		lst = lst->next;
	}
	return (begin_new);
}
