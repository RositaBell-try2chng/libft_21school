/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:13:49 by rbell             #+#    #+#             */
/*   Updated: 2021/10/10 14:16:04 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	ln;
	char	*sub;

	ln = 0;
	while (s[ln])
		ln++;
	if (ln < len)
		sub = malloc(sizeof(char) * (ln + 1));
	else
		sub = malloc(sizeof(char) * (len + 1));
	if (NULL == sub)
		return (NULL);
	i = 0;
	while (i < len && i + start < ln)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
