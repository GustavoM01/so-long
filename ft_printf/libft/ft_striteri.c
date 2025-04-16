/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:44:18 by gmaldona          #+#    #+#             */
/*   Updated: 2022/03/10 13:01:02 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	size;
	unsigned int	i;

	if (s)
	{
		size = ft_strlen(s) + 1;
		i = 0;
		while (i < size - 1)
		{
			f(i, s + i);
			i++;
		}
	}
}
