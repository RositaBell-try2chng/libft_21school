/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:10:02 by rbell             #+#    #+#             */
/*   Updated: 2021/10/11 13:10:06 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*curr_adr;

	if (NULL == lst || NULL == *lst)
		return ;
	curr_adr = *lst;
	while (curr_adr)
	{
		del(curr_adr->content);
		tmp = curr_adr->next;
		free(curr_adr);
		curr_adr = tmp;
	}
	*lst = NULL;
}
