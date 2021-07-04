/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_num_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:47:18 by narakely          #+#    #+#             */
/*   Updated: 2021/03/24 20:54:34 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_flags_num_6(t_flags_types ft,
				int *sym_count, int prec, int *width)
{
	(*width)--;
	(*sym_count)++;
	if (prec == 0 && ft.prec_dot == 0)
		ft_putchar_fd('-', 1);
}

void			ft_flags_num_7(int prec, t_flags_types ft, int *sym_count)
{
	if (prec <= 0 && ft.prec_dot != 0)
		ft_putchar_fd(' ', 1);
	else
		ft_putchar_fd('0', 1);
	(*sym_count)++;
}

void			ft_flags_num_8(int width, int prec, int num, int *sym_count)
{
	if (width > prec)
		width -= prec;
	else
		width = 0;
	prec -= ft_num_length(num);
	if (num < 0)
		width--;
	while (width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*sym_count)++;
	}
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num *= -1;
		width--;
		(*sym_count)++;
	}
	while (prec-- > 0)
	{
		ft_putnbr_fd(0, 1);
		(*sym_count)++;
	}
	ft_putnbr_fd(num, 1);
}

int				ft_flags_num_9(int num, int width, int prec, t_flags_types ft)
{
	int sym_count;

	sym_count = 0;
	width -= ft_num_length(num);
	if (num < 0)
	{
		width--;
		sym_count++;
	}
	while (width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		sym_count++;
	}
	if (prec == 0 && ft.prec_dot == 1 && num == 0)
	{
		ft_putchar_fd(' ', 1);
		sym_count++;
	}
	else
	{
		ft_putnbr_fd(num, 1);
		sym_count += (num == 0 ? 1 : ft_num_length(num));
	}
	return (sym_count);
}

int				ft_flags_num_10(int prec, int width,
				va_list params, t_flags_types ft)
{
	int	num;
	int sym_count;

	sym_count = 0;
	num = va_arg(params, int);
	if (prec > (sym_count = ft_num_length(num)))
		ft_flags_num_8(width, prec, num, &sym_count);
	else
		sym_count = ft_flags_num_9(num, width, prec, ft);
	return (sym_count);
}
