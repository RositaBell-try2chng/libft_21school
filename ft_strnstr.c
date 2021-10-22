/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:13:33 by rbell             #+#    #+#             */
/*   Updated: 2021/10/11 12:53:32 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_str(const char *haystack, const char *needle, \
		size_t ln, size_t lh)
{
	size_t	i;

	i = 0;
	while (i < lh - ln + 1)
	{
		if (0 == ft_strncmp((haystack + i), needle, ln))
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ln;
	size_t	lh;
	char	*result;

	ln = 0;
	lh = 0;
	while (needle[ln])
		ln++;
	if (0 == ln)
		return ((char *)haystack);
	while (haystack[lh])
		lh++;
	if (lh > len)
		lh = len;
	if (lh < ln)
		return (NULL);
	result = find_str(haystack, needle, ln, lh);
	return (result);
}
