/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:30:33 by gmaldona          #+#    #+#             */
/*   Updated: 2025/04/16 18:03:35 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_ph		*save_ph_information(char *current_add);
static short	is_valid_format(char *msg, t_ph *ph);
static void		set_default_ph(t_ph *ph);
static void		set_nbr_flag(char c, t_ph *ph);

void	read_msg(t_list **ph_list, char *msg)
{
	int		i;
	t_ph	*current_ph;

	i = 0;
	while (msg[i])
	{
		if (PH == msg[i])
		{
			current_ph = save_ph_information(msg + i);
			if (current_ph != NULL)
			{
				ft_lstadd_back(ph_list, ft_lstnew(current_ph));
				i += current_ph->size;
			}
		}
		i++;
	}
}

static t_ph	*save_ph_information(char *current_add)
{
	t_ph	*ph;

	ph = malloc(sizeof(t_ph));
	if (ph)
	{
		ph->start = NULL;
		set_default_ph(ph);
		if (is_valid_format(current_add + 1, ph))
			ph->start = current_add;
		else
		{
			free(ph);
			ph = NULL;
		}		
	}
	return (ph);
}

static short	is_valid_format(char *msg, t_ph *ph)
{
	int		i;

	i = 0;
	while (msg[i])
	{
		ph->size++;
		if (msg[i] == '#')
			ph->numeral_flag = 1;
		else if (msg[i] == ' ')
			ph->s_flag = 1;
		else if (msg[i] == '+')
			ph->sg_flag = 1;
		else if (ft_isdigit(msg[i]))
			set_nbr_flag(msg[i], ph);
		else if (ft_strchr(FMTS, msg[i]) || msg[i] == PH)
		{
			ph->type = msg[i];
			return (1);
		}
		else if (!ft_isalnum(msg[i]))
			return (0);
		i++;
	}
	return (0);
}

static void	set_default_ph(t_ph *ph)
{
	ph->numeral_flag = 0;
	ph->sg_flag = 0;
	ph->s_flag = 0;
	ph->size = 0;
	ph->nbr_flag = 0;
}

static void	set_nbr_flag(char c, t_ph *ph)
{
	ph->nbr_flag *= 10;
	ph->nbr_flag += (c - '0');
}
