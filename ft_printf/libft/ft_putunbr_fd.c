/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:37:24 by gmaldona          #+#    #+#             */
/*   Updated: 2025/04/16 18:08:48 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_recursive_put_u(unsigned long n, int fd);

int	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned long	nlong;
	int				count;

	nlong = n;
	count = 0;
	count += ft_recursive_put_u(nlong, fd);
	return (count);
}

static int	ft_recursive_put_u(unsigned long n, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (n / 10 != 0)
		count = ft_recursive_put_u(n / 10, fd);
	c = (n % 10) + '0';
	ft_putchar_fd(c, fd);
	return (count + 1);
}
