/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_neg_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:37:16 by narakely          #+#    #+#             */
/*   Updated: 2021/03/24 15:37:27 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_flags_neg_width_1(int width, int prec,
				int *sym_count, int num)
{
	if (width > prec)
		width -= prec;
	else
		width = 0;
	if (num < 0)
		width--;
	prec -= ft_num_length(num);
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num *= -1;
		(*sym_count)++;
	}
	while (prec-- > 0)
	{
		ft_putnbr_fd(0, 1);
		(*sym_count)++;
	}
	ft_putnbr_fd(num, 1);
	while (width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*sym_count)++;
	}
}

static	void	ft_flags_neg_width_2(int prec, t_flags_types ft, int num)
{
	if (prec == 0 && ft.prec_dot == 1 && num == 0)
		ft_putchar_fd(' ', 1);
	else
		ft_putnbr_fd(num, 1);
}

int				ft_flags_neg_width(t_flags_types ft,
				va_list params, int width, int prec)
{
	int num;
	int sym_count;

	num = va_arg(params, int);
	if (prec > (sym_count = (ft_num_length(num))))
		ft_flags_neg_width_1(width, prec, &sym_count, num);
	else
	{
		if (num < 0)
		{
			ft_putchar_fd('-', 1);
			num *= -1;
			sym_count++;
			width--;
		}
		width -= ft_num_length(num);
		ft_flags_neg_width_2(prec, ft, num);
		while (width-- > 0)
		{
			ft_putchar_fd(' ', 1);
			sym_count++;
		}
	}
	return (sym_count);
}
