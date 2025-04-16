/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_writer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:18:47 by gmaldona          #+#    #+#             */
/*   Updated: 2022/10/02 13:20:22 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		writer_cataloger(char *msg, va_list args, t_list **ph_list);
static int		print_ph(t_list **list, va_list args);
static int		ft_put_s(char *arg, t_ph *ph);
static int		print_flags(char format, t_ph *ph, va_list args_cpy);

int	write_msg(char *msg, va_list args, t_list **ph_list)
{
	int		count;
	t_list	*first_item;

	count = 0;
	first_item = *ph_list;
	count = writer_cataloger(msg, args, ph_list);
	*ph_list = first_item;
	va_end(args);
	return (count);
}

static int	writer_cataloger(char *msg, va_list args, t_list **ph_l)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (msg[i])
	{
		if (*ph_l != NULL && (msg + i) == ((t_ph *)((*ph_l)->content))->start)
		{
			i += ((t_ph *)(*ph_l)->content)->size;
			count += print_ph(ph_l, args);
			*ph_l = (*ph_l)->next;
		}
		else if (msg[i] == PH)
			while (ft_strrchr(FLAGS, msg[i + 1]))
				i++;
		else
		{
			ft_putchar_fd(msg[i], 1);
			count++;
		}
	i++;
	}
	return (count);
}

static int	print_ph(t_list **list, va_list args)
{
	char	fm;
	va_list	cpy;
	int		size;

	va_copy(cpy, args);
	fm = ((t_ph *)((*list)->content))->type;
	size = print_flags(fm, (*list)->content, cpy);
	if (fm == 'c')
		size += ft_putchar_fd((char) va_arg(args, int), 1);
	else if (fm == 's')
		size += ft_putstr_fd(va_arg(args, char *), 1);
	else if (fm == 'p')
		size += ft_putptr(va_arg(args, unsigned long));
	else if (fm == 'd' || fm == 'i')
		size += ft_putnbr_fd(va_arg(args, int), 1);
	else if (fm == 'u')
		size += ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (fm == 'x')
		size += ft_puthex_l(va_arg(args, unsigned int));
	else if (fm == 'X')
		size += ft_puthex_u(va_arg(args, unsigned int));
	else if (fm == PH)
		size += ft_putchar_fd(PH, 1);
	va_end(cpy);
	return (size);
}

static	int	print_flags(char fm, t_ph *ph, va_list cpy)
{
	int		result;

	result = 0;
	if ((ph->s_flag || ph->sg_flag) && (fm == 'd' || fm == 'i'))
	{
		if (va_arg(cpy, int) >= 0)
		{
			if (ph->sg_flag)
				ft_putchar_fd('+', 1);
			else
				ft_putchar_fd(' ', 1);
			result++;
		}
	}
	else if (ph->numeral_flag && (fm == 'x' || fm == 'X'))
		result += ft_put_prefix(fm, va_arg(cpy, unsigned int));
	else if ((fm == 's' || fm == 'c') && ph->s_flag)
		result += ft_put_s(va_arg(cpy, char *), ph);
	return (result);
}

static int	ft_put_s(char *arg, t_ph *ph)
{
	int	i;

	i = 0;
	while (i < ((int) ph->nbr_flag - (int) ft_strlen(arg)))
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	return (i);
}
