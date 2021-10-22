/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:51:27 by rbell             #+#    #+#             */
/*   Updated: 2021/10/10 12:51:43 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst == src)
		return (dst);
	while (n > 0)
	{
		*((unsigned char *)(dst + n - 1)) = *((unsigned char *)(src + n - 1));
		n--;
	}
	return ((void *)dst);
}
