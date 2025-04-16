/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:49:18 by gmaldona          #+#    #+#             */
/*   Updated: 2022/03/04 17:16:25 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	sdst;
	size_t	ssrc;
	size_t	max_append;
	size_t	i;

	sdst = ft_strlen(dst);
	ssrc = ft_strlen(src);
	max_append = dstsize - sdst - 1;
	i = 0;
	if (dstsize > 0 && sdst < dstsize)
	{
		while (i < max_append && src[i])
		{
			*(dst + sdst + i) = *(src + i);
			i++;
		}
		*(dst + sdst + i) = '\0';
		return (sdst + ssrc);
	}
	return (sdst + ssrc - (sdst - dstsize));
}
