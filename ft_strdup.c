/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:25:55 by rbell             #+#    #+#             */
/*   Updated: 2021/10/10 15:26:39 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*new;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	new = malloc(sizeof(char) * (len + 1));
	if (NULL == new)
		return (NULL);
	while (i < len)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
