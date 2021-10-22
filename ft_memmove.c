/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:54:45 by rbell             #+#    #+#             */
/*   Updated: 2021/10/10 17:03:14 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (src > dst)
	{
		while (i < len)
		{
			*((unsigned char *)(dst + i)) = *((unsigned char *)(src + i));
			i++;
		}
		i++;
	}
	else if (src < dst)
	{
		i = 1;
		while (i <= len)
		{
			*((unsigned char *)(dst + len - i)) = \
				*((unsigned char *)(src + len - i));
			i++;
		}
	}
	return ((void *)dst);
}
