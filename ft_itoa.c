/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:35:45 by rbell             #+#    #+#             */
/*   Updated: 2021/10/11 16:52:50 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_cnt(int n)
{
	size_t	i;

	i = (n < 0);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_put_nbr_mod(char	*str, size_t i, long int n)
{
	if (n < 0)
		n *= -1;
	if (n / 10 > 0)
		ft_put_nbr_mod(str, (i - 1), (n / 10));
	str[i] = (n % 10 + '0');
}

char	*ft_itoa(int n)
{
	char		*str;
	int			cnt;

	cnt = find_cnt(n);
	str = malloc(sizeof(char) * (cnt + 1));
	if (NULL == str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		str[0] = '-';
		ft_put_nbr_mod(str, (cnt - 1), n);
		str[cnt] = '\0';
	}
	return (str);
}
