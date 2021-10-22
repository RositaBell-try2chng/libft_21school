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

	i = 0;
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

static char	*give_me_memory(int cnt, int n)
{
	if (n <= 0)
		return ((char *)malloc(sizeof(char) * (cnt + 2)));
	else
		return ((char *)malloc(sizeof(char) * (cnt + 1)));
}

char	*ft_itoa(int n)
{
	char		*str;
	int			cnt;

	cnt = find_cnt(n);
	str = give_me_memory(cnt, n);
	if (NULL == str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		ft_put_nbr_mod(str, cnt, n);
		str[cnt + 1] = '\0';
	}
	else if (n > 0)
	{
		ft_put_nbr_mod(str, (cnt - 1), n);
		str[cnt] = '\0';
	}
	else
	{
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}
