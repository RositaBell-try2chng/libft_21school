/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:24:44 by rbell             #+#    #+#             */
/*   Updated: 2021/10/10 17:08:36 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_words(char const *s, char c)
{
	size_t			i;
	int				flg;
	unsigned int	cnt;

	flg = 1;
	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (flg == 1)
				cnt++;
			flg = 0;
		}
		else
			flg = 1;
		i++;
	}
	return (cnt);
}

static char	*str_mod_dup(const char *s, char c, char **split, size_t j)
{
	size_t	i;
	char	*new;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	if (NULL == new)
	{
		while (--j >= 0)
			free(split[j]);
		return (NULL);
	}
	i = 0;
	while (s[i] != c && s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static void	real_split(char const *s, char **split, char c, size_t i)
{
	int		flg;
	size_t	j;

	flg = 1;
	j = -1;
	while (s[++j])
	{
		if (s[j] != c)
		{
			if (flg == 1)
			{
				split[i] = str_mod_dup(&s[j], c, split, i);
				if (NULL == split[i])
				{
					free(split);
					split = NULL;
				}
				i++;
			}
			flg = 0;
		}
		else
			flg = 1;
	}
}

char	**ft_split(char const *s, char c)
{
	unsigned int	cnt;
	char			**split;

	cnt = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (NULL == split)
		return (NULL);
	split[cnt] = NULL;
	real_split(s, split, c, 0);
	return (split);
}
