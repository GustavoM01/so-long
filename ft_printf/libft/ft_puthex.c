/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:50:26 by gmaldona          #+#    #+#             */
/*   Updated: 2022/10/02 00:17:45 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_puthex(unsigned long nbr, char *xX);
int			ft_put_prefix(char format, unsigned long nbr);

int	ft_putptr(unsigned long nbr)
{
	int	count;

	count = 2;
	ft_putstr_fd("0x", 1);
	count += ft_puthex(nbr, HEX_L);
	return (count);
}

int	ft_puthex_l(unsigned long nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	count += ft_puthex(nbr, HEX_L);
	return (count);
}

int	ft_puthex_u(unsigned long nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	count += ft_puthex(nbr, HEX_U);
	return (count);
}

static int	ft_puthex(unsigned long nbr, char *xX)
{
	int	count;

	count = 0;
	if (nbr / HEX_SIZE != 0)
		count += ft_puthex(nbr / HEX_SIZE, xX);
	write(1, &(xX[nbr % HEX_SIZE]), 1);
	return (count + 1);
}

int	ft_put_prefix(char format, unsigned long nbr)
{
	if (nbr != 0)
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(format, 1);
		return (2);
	}
	return (0);
}
