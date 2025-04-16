/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:02:11 by gmaldona          #+#    #+#             */
/*   Updated: 2025/04/16 18:11:25 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static char			*ft_return_empty(void);

static unsigned int	ft_new_size(const char *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	size;

	if (!s)
		return (NULL);
	if (!(start < ft_strlen(s)))
		return (ft_return_empty());
	size = ft_new_size(s, start, len);
	s2 = (char *) malloc(sizeof(*s) * size);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s + start, size);
	return (s2);
}

static char	*ft_return_empty(void)
{
	char	*empty;

	empty = malloc(sizeof(char) * 1);
	if (empty)
	{
		*empty = '\0';
		return (empty);
	}
	return (NULL);
}

static unsigned int	ft_new_size(const char *s, unsigned int start, size_t len)
{
	if ((ft_strlen(s) - start) <= len)
		return (ft_strlen(s) - start + 1);
	else
		return (len + 1);
}
