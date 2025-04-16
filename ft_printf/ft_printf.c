/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:34:19 by gmaldona          #+#    #+#             */
/*   Updated: 2022/10/02 00:10:26 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *msg, ...)
{
	int		char_count;
	t_list	**ph_list;
	va_list	args;

	char_count = 0;
	ph_list = malloc(sizeof(t_list *));
	*ph_list = NULL;
	if (ph_list)
	{
		va_start(args, msg);
		read_msg(ph_list, (char *) msg);
		char_count = write_msg((char *) msg, args, ph_list);
	}	
	va_end(args);
	ft_lstclear(ph_list, (void *) free);
	free(ph_list);
	return (char_count);
}
