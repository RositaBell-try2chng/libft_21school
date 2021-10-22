/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:22:17 by rbell             #+#    #+#             */
/*   Updated: 2021/10/10 15:22:46 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new;

	i = 0;
	while (s[i])
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (NULL == new)
		return (NULL);
	new[i] = '\0';
	while (i > 0)
	{
		new[i - 1] = f((i - 1), s[i - 1]);
		i--;
	}
	return (new);
}
