/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:48:20 by gmaldona          #+#    #+#             */
/*   Updated: 2022/03/10 18:13:23 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	s_cpy;

	s_cpy = ft_strlen(s1) + 1;
	s2 = malloc (sizeof(char) * s_cpy);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, s_cpy);
	return (s2);
}
