/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:05:20 by gmaldona          #+#    #+#             */
/*   Updated: 2022/09/01 00:59:08 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;

	i = -1;
	cc = (char) c;
	while (s[++i] != '\0')
	{
		if (s[i] == cc)
			return ((char *)(s + i));
	}
	if (s[i] == '\0' && cc == '\0')
		return ((char *)(s + i));
	return (NULL);
}
