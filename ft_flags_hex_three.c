/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_hex_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:04:24 by narakely          #+#    #+#             */
/*   Updated: 2021/03/26 17:07:20 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags_hex_5(int width, int prec,
				va_list params, t_flags_types ft)
{
	int num;
	int sym_count;

	sym_count = 0;
	num = va_arg(params, int);
	ft_putnbr_base_count(num, ft.type_bigx ? "0123456789ABCDEF" :
						"0123456789abcdef", &sym_count);
	if (prec > sym_count)
		sym_count = ft_flags_hex_6(width, prec, ft, num);
	else
	{
		prec = prec == 0 ? 0 : -1;
		width -= sym_count;
		while (width-- > 0)
			ft_flags_hex_7(prec, ft, &sym_count);
		if (prec == 0 && ft.prec_dot == 1 && num == 0)
			ft_putchar_fd(' ', 1);
		else
			ft_putnbr_base(num, ft.type_bigx ? "0123456789ABCDEF" :
						"0123456789abcdef");
	}
	return (sym_count);
}

int	ft_flags_hex_9(int width, int prec, int num, t_flags_types ft)
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
		ft_putchar_fd(' ', 1);
		sym_count++;
	}
	while (prec-- > 0)
	{
		ft_putuint_fd(0, 1);
		sym_count++;
	}
	ft_putnbr_base(num, ft.type_bigx ? "0123456789ABCDEF" :
					"0123456789abcdef");
	return (sym_count);
}

int	ft_flags_hex_8(int width, int prec,
				t_flags_types ft, va_list params)
{
	int num;
	int sym_count;

	sym_count = 0;
	num = va_arg(params, int);
	ft_putnbr_base_count(num, ft.type_bigx ? "0123456789ABCDEF" :
						"0123456789abcdef", &sym_count);
	if (prec > sym_count)
		sym_count = ft_flags_hex_9(width, prec, num, ft);
	else
	{
		width -= sym_count;
		while (width-- > 0)
		{
			ft_putchar_fd(' ', 1);
			sym_count++;
		}
		if (prec == 0 && ft.prec_dot == 1 && num == 0)
			ft_putchar_fd(' ', 1);
		else
			ft_putnbr_base(num, ft.type_bigx ? "0123456789ABCDEF" :
			"0123456789abcdef");
	}
	return (sym_count);
}

int	ft_flags_hex_10(int prec, int width,
					va_list params, t_flags_types ft)
{
	int sym_count;

	sym_count = 0;
	if (ft.ignore || ft.flag_minus || width < 0)
		sym_count += ft_flags_hex_2(width, prec, params, ft);
	else if (ft.flag_zero)
		sym_count += ft_flags_hex_5(width, prec, params, ft);
	else
		sym_count += ft_flags_hex_8(width, prec, ft, params);
	return (sym_count);
}
