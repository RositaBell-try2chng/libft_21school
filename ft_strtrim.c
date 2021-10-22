/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:18:08 by rbell             #+#    #+#             */
/*   Updated: 2021/10/11 15:15:52 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_sub_str(char const *s, unsigned int start, size_t len)
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

static size_t	find_first_set(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		flg;

	i = 0;
	flg = 1;
	while (flg && s1[i])
	{
		j = 0;
		flg = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				flg = 1;
			j++;
		}
		i++;
	}
	return (i - 1);
}

static size_t	find_last_set(char const *s1, char const *set, size_t end)
{
	size_t	j;
	int		flg;

	flg = 1;
	while (flg && end > 0)
	{
		j = 0;
		flg = 0;
		while (set[j])
		{
			if (s1[end - 1] == set[j])
				flg = 1;
			j++;
		}
		end--;
	}
	return (end + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	length;

	length = 0;
	while (s1[length])
		length++;
	start = find_first_set(s1, set);
	end = find_last_set(s1, set, length);
	if (end > start)
		trim = ft_sub_str(s1, start, (end - start));
	else
	{
		trim = malloc(sizeof(char));
		trim[0] = '\0';
	}
	return (trim);
}
