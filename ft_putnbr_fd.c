/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:40:27 by rbell             #+#    #+#             */
/*   Updated: 2021/10/10 17:04:00 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	if (n / 10 > 0)
		ft_putnbr_fd(n / 10, fd);
	else if (n / 10 < 0)
		ft_putnbr_fd(n / -10, fd);
	if (n >= 0)
		ft_putchar_fd(n % 10 + '0', fd);
	else
		ft_putchar_fd(n % 10 * -1 + '0', fd);
}
