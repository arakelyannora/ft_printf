/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_hex_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:01:57 by narakely          #+#    #+#             */
/*   Updated: 2021/03/26 17:08:10 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_flags_hex_3(int width, int prec, int num, t_flags_types ft)
{
	int sym_count;

	sym_count = 0;
	ft_putnbr_base_count(num, ft.type_bigx ? "0123456789ABCDEF" :
						"0123456789abcdef", &sym_count);
	width -= sym_count;
	if (prec == 0 && ft.prec_dot == 1 && num == 0)
		ft_putchar_fd(' ', 1);
	else
		ft_putnbr_base(num, ft.type_bigx ? "0123456789ABCDEF" :
						"0123456789abcdef");
	while (width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		sym_count++;
	}
	return (sym_count);
}

void			ft_flags_hex_4(int *width, int *prec, int *sym_count)
{
	if (*width > *prec)
		*width -= *prec;
	else
		*width = 0;
	*prec -= *sym_count;
	while ((*prec)-- > 0)
	{
		ft_putuint_fd(0, 1);
		(*sym_count)++;
	}
}

int				ft_flags_hex_2(int width, int prec,
			va_list params, t_flags_types ft)
{
	int num;
	int sym_count;

	sym_count = 0;
	if (width < 0)
		width *= -1;
	num = va_arg(params, int);
	ft_putnbr_base_count(num, ft.type_bigx ? "0123456789ABCDEF" :
						"0123456789abcdef", &sym_count);
	if (prec > sym_count)
	{
		ft_flags_hex_4(&width, &prec, &sym_count);
		ft_putnbr_base(num, ft.type_bigx ? "0123456789ABCDEF"
						: "0123456789abcdef");
		while (width-- > 0)
		{
			ft_putchar_fd(' ', 1);
			sym_count++;
		}
	}
	else
		sym_count = ft_flags_hex_3(width, prec, num, ft);
	return (sym_count);
}

int				ft_flags_hex_6(int width, int prec, t_flags_types ft, int num)
{
	int sym_count;

	sym_count = 0;
	ft_putnbr_base_count(num, ft.type_bigx ? "0123456789ABCDEF" :
						"0123456789abcdef", &sym_count);
	if (width > prec)
		width -= prec;
	else
		width = 0;
	prec -= sym_count;
	while (width-- > 0)
	{
		if (prec == 0)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		sym_count++;
	}
	while (prec-- > 0)
	{
		ft_putuint_fd(0, 1);
		sym_count++;
	}
	ft_putnbr_base(num, ft.type_bigx ? "0123456789ABCDEF" : "0123456789abcdef");
	return (sym_count);
}

void			ft_flags_hex_7(int prec, t_flags_types ft, int *sym_count)
{
	if (prec <= 0 && ft.prec_dot != 0)
		ft_putchar_fd(' ', 1);
	else
		ft_putchar_fd('0', 1);
	(*sym_count)++;
}
