/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:37:24 by gmaldona          #+#    #+#             */
/*   Updated: 2025/04/16 18:08:20 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_recursive_put(long n, int fd);

int	ft_putnbr_fd(int n, int fd)
{
	long	nlong;
	int		count;

	nlong = n;
	count = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nlong *= -1;
		count++;
	}
	count += ft_recursive_put(nlong, fd);
	return (count);
}

static int	ft_recursive_put(long n, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (n / 10 != 0)
		count = ft_recursive_put(n / 10, fd);
	c = (n % 10) + '0';
	ft_putchar_fd(c, fd);
	return (count + 1);
}
