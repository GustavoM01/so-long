/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:24:14 by gmaldona          #+#    #+#             */
/*   Updated: 2022/03/10 12:56:41 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	unsigned int	i;
	char			*ptr;

	if (!s)
		return (NULL);
	size = ft_strlen(s) + 1;
	i = 0;
	ptr = malloc(sizeof(*s) * size);
	if (!ptr)
		return (NULL);
	while (i < size - 1)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
