/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:53:05 by gmaldona          #+#    #+#             */
/*   Updated: 2022/03/11 17:42:13 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		s_len;
	char	cc;

	s_len = (int) ft_strlen(s);
	cc = (char) c;
	while (s_len >= 0)
	{
		if (cc == s[s_len])
			return ((char *)(s + s_len));
		s_len--;
	}
	return (NULL);
}
