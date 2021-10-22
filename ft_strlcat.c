/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:11:30 by rbell             #+#    #+#             */
/*   Updated: 2021/10/11 19:10:32 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	tmp = i;
	if (dstsize > i && dstsize)
	{
		while (src[j] && (i + 1) < dstsize)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	while (src[j])
		j++;
	return (tmp + j);
}
