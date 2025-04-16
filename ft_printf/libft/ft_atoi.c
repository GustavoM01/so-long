/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:59:27 by gmaldona          #+#    #+#             */
/*   Updated: 2025/04/16 18:06:48 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int				ft_get_nbr(char *str, int is_neg);

static unsigned long	ft_max_int(void);

int	ft_atoi(const char *str)
{
	int		i;
	int		is_neg;
	int		sign;
	char	*ptr;

	i = 0;
	is_neg = 0;
	sign = 0;
	ptr = (char *)str;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (sign)
			return (0);
		sign++;
		if (str[i++] == 45)
			is_neg++;
	}
	return (ft_get_nbr(ptr + i, is_neg));
}

static int	ft_get_nbr(char *str, int is_neg)
{
	unsigned long	num;

	num = 0;
	while (*str >= '0' && *str <= '9')
		num = (num * 10) + (*(str++) - '0');
	if (num > ft_max_int() && !is_neg)
		return (-1);
	if (num > ft_max_int() + 1 && is_neg)
		return (0);
	if (is_neg)
		return (num * -1);
	return (num);
}

static unsigned long	ft_max_int(void)
{
	return ((unsigned int)(~0) >> 1);
}
