/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:58:38 by gmaldona          #+#    #+#             */
/*   Updated: 2022/03/11 17:24:35 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*ptr;
	unsigned char	uc;

	i = 0;
	ptr = (unsigned char *) s;
	uc = (unsigned char) c;
	while (i < n)
	{
		if (ptr[i] == uc)
			return (ptr + i);
		i ++;
	}
	return (NULL);
}
