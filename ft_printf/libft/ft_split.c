/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:12:43 by gmaldona          #+#    #+#             */
/*   Updated: 2025/04/16 18:10:05 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_countwords(const char *s, char c);

static int	*ft_limits(const char *s, char c, unsigned long count);

static void	ft_set(char **p, const char *s, long c, int *l);

char	**ft_split(const char *s, char c)
{
	long	count;
	int		*w_lim;
	char	**ret_ptr;

	if (!s)
		return (NULL);
	count = ft_countwords(s, c);
	ret_ptr = malloc(sizeof(char *) * (count + 1));
	if (!(ret_ptr))
		return (NULL);
	ret_ptr[count] = NULL;
	if (!count)
		return (ret_ptr);
	w_lim = ft_limits(s, c, count);
	ft_set(ret_ptr, s, count, w_lim);
	return (ret_ptr);
}

static long	ft_countwords(const char *s, char c)
{
	long	i;
	int		inside_word;
	int		count;

	i = 0;
	inside_word = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (!inside_word)
			{
				inside_word = 1;
				count++;
			}
			i++;
		}
		inside_word = 0;
	}
	return (count);
}

static int	*ft_limits(const char *s, char c, unsigned long count)
{
	long	i;
	int		j;
	int		*ptr;

	i = 0;
	j = 0;
	ptr = malloc(sizeof(int) * (count * 2));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			return (ptr);
		ptr[j] = i;
		j++;
		while (s[i] && s[i] != c)
			i++;
		ptr[j] = i;
		j++;
	}
	return (ptr);
}

static void	ft_set(char **p, const char *s, long c, int *l)
{
	long	i;
	int		j;

	i = 0;
	j = 0;
	while (i < c)
	{
		p[i] = ft_substr(s, l[j], l[j + 1] - l[j]);
		i++;
		j = j + 2;
	}
	free(l);
}
