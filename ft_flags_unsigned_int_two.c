/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_unsigned_int_two.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:50:01 by narakely          #+#    #+#             */
/*   Updated: 2021/03/24 21:50:09 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void		ft_flags_uns_7(int width, int prec,
					int *sym_count, int num)
{
	if (width > prec)
		width -= prec;
	else
		width = 0;
	prec -= ft_uns_num_length(num);
	while (width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*sym_count)++;
	}
	while (prec-- > 0)
	{
		ft_putuint_fd(0, 1);
		(*sym_count)++;
	}
	ft_putuint_fd(num, 1);
}

int					ft_flags_uns_6(int prec, int width,
					t_flags_types ft, va_list params)
{
	int sym_count;
	int num;

	num = va_arg(params, int);
	if (prec > (sym_count = ft_uns_num_length(num)))
		ft_flags_uns_7(width, prec, &sym_count, num);
	else
	{
		width -= ft_uns_num_length(num);
		while (width-- > 0)
		{
			ft_putchar_fd(' ', 1);
			sym_count++;
		}
		if (prec == 0 && ft.prec_dot == 1 && num == 0)
			ft_putchar_fd(' ', 1);
		else
			ft_putuint_fd(num, 1);
	}
	return (sym_count);
}

int					ft_flags_uns_4(va_list params, int width,
					int prec, t_flags_types ft)
{
	int sym_count;
	int num;

	sym_count = 0;
	num = va_arg(params, int);
	if (prec > (sym_count = ft_uns_num_length(num)))
		ft_flags_uns_5(width, prec, num, &sym_count);
	else
	{
		prec = prec == 0 ? 0 : -1;
		width -= ft_uns_num_length(num);
		while (width-- > 0)
		{
			if (prec <= 0 && ft.prec_dot != 0)
				ft_putchar_fd(' ', 1);
			else
				ft_putchar_fd('0', 1);
			sym_count++;
		}
		if (prec == 0 && ft.prec_dot == 1 && num == 0)
			ft_putchar_fd(' ', 1);
		else
			ft_putuint_fd(num, 1);
	}
	return (sym_count);
}
