/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:29:16 by gmaldona          #+#    #+#             */
/*   Updated: 2022/03/08 13:08:01 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	new_size;

	if (!s1 || !s2)
		return (NULL);
	new_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *) malloc(sizeof(*s1) * new_size);
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, new_size);
	ft_strlcat(join, s2, new_size);
	return (join);
}
