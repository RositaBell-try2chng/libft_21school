/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:15:28 by rbell             #+#    #+#             */
/*   Updated: 2021/10/22 12:01:00 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skipspace(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	return (i);
}

static int	check_max(const char *s, int sign)
{
	size_t	i;
	char	*s_max;

	s_max = "9223372036854775807";
	i = 0;
	while (s[i] > 47 && s[i] < 58)
		i++;
	if (i < 19)
		return (1);
	else if (i > 19)
		return ((sign + 1) / -2);
	i = 0;
	while (i < 19)
	{
		if (s[i] > s_max[i])
			return ((sign + 1) / (-2));
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	long long	res;
	int			sign;
	int			max;

	res = 0;
	sign = 1;
	i = skipspace(str);
	if (str[i] == 45)
		sign = -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	max = (check_max(str + i, sign));
	if (max == -1 || max == 0)
		return (max);
	while (str[i] > 47 && str[i] < 58)
	{
		res += str[i] - '0';
		if (str[i + 1] > 47 && str[i + 1] < 58)
			res *= 10;
		i++;
	}
	return ((int)(res * sign));
}
