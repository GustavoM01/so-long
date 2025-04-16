/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:31:37 by gmaldona          #+#    #+#             */
/*   Updated: 2025/04/16 18:11:54 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	ft_find(const char *h, const char *n, size_t nl);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	size_t	h_len;
	size_t	lim;
	size_t	i;
	size_t	c_len;

	n_len = ft_strlen(needle);
	if (!n_len)
		return ((char *) haystack);
	h_len = ft_strlen(haystack);
	if (n_len > h_len)
		return (NULL);
	lim = h_len - n_len;
	i = 0;
	c_len = len;
	while (len && i <= lim && i <= c_len - n_len)
	{
		if (ft_find(haystack + i, needle, n_len))
			return ((char *)(haystack + i));
		i++;
		len--;
	}
	return (NULL);
}

static size_t	ft_find(const char *h, const char *n, size_t nl)
{
	size_t	i;

	i = 0;
	while (h[i] && n[i] && h[i] == n[i])
		i++;
	if (i == nl)
		return (1);
	return (0);
}
