/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:25:22 by rbell             #+#    #+#             */
/*   Updated: 2021/10/10 15:25:33 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	i;

	i = 0;
	arr = malloc(count * size);
	if (NULL == arr)
		return (NULL);
	while (i < size * count)
	{
		((char *)arr)[i] = '\0';
		i++;
	}
	return (arr);
}
