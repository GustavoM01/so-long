/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:38:06 by gmaldona          #+#    #+#             */
/*   Updated: 2022/10/02 13:17:01 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FMTS "cspdiuxX"
# define FLAGS "# +"
# define PH '%'
# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_placeholder
{
	char			*start;
	char			type;
	unsigned short	size;
	short			numeral_flag;
	short			s_flag;
	short			sg_flag;
	short			nbr_flag;

}	t_ph;

int		ft_printf(char const *msg, ...);
void	read_msg(t_list **list, char *str);
int		write_msg(char *msg, va_list args, t_list **ph_list);

#endif
