/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:08:54 by rbell             #+#    #+#             */
/*   Updated: 2021/10/11 13:09:08 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr_adr;

	if (NULL == lst)
		return ;
	if (NULL == *lst)
	{
		*lst = new;
		return ;
	}
	if (*lst == new)
		return ;
	curr_adr = *lst;
	while (curr_adr->next != NULL)
		curr_adr = curr_adr->next;
	curr_adr->next = new;
}
