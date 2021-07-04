/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:38:40 by narakely          #+#    #+#             */
/*   Updated: 2021/03/24 20:54:08 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_flags_num_1(int *width, int *prec,
				va_list params, t_flags_types ft)
{
	*width = 0;
	*prec = 0;
	if (ft.width_ast)
		*width = va_arg(params, int);
	if (ft.width)
		*width = ft.width;
	if (ft.prec_dot_ast)
		*prec = va_arg(params, int);
	if (ft.prec_dot_number)
		*prec = ft.prec_dot_number;
}

void			ft_flags_num_11(t_flags_types ft, int prec,
				int *sym_count, va_list params)
{
	int num;

	num = va_arg(params, int);
	*sym_count = ft_num_length(num);
	if (prec == 0 && ft.prec_dot && num == 0)
	{
		*sym_count = 0;
		return ;
	}
	if (num < 0)
		(*sym_count)++;
	ft_putnbr_fd(num, 1);
}

int				ft_flags_num_12(va_list params, int prec,
				t_flags_types ft, int width)
{
	int sym_count;
	int num;

	sym_count = 0;
	num = va_arg(params, int);
	if (prec > (sym_count = ft_num_length(num)))
		ft_flags_num_5(width, prec, &sym_count, num);
	else
	{
		prec = prec == 0 ? 0 : -1;
		width -= ft_num_length(num);
		if (num < 0)
			ft_flags_num_6(ft, &sym_count, prec, &width);
		while (width-- > 0)
			ft_flags_num_7(prec, ft, &sym_count);
		if (num < 0)
		{
			if ((prec != 0 && num != -2147483648)
				|| (ft.prec_dot != 0 && prec == 0))
				ft_putchar_fd('-', 1);
			num *= -1;
		}
		ft_flags_num_3(prec, ft, num);
	}
	return (sym_count);
}

int				ft_flags_num_14(va_list params,
				t_flags_types ft, int width, int prec)
{
	int sym_count;
	int num;

	sym_count = 0;
	num = va_arg(params, int);
	if (prec > (sym_count = ft_num_length(num)))
		ft_flags_num_2(width, prec, num, &sym_count);
	else
		sym_count += ft_flags_num_4(num, width, prec, ft);
	return (sym_count);
}

int				ft_flags_num(t_flags_types ft, va_list params)
{
	int prec;
	int width;
	int sym_count;

	sym_count = 0;
	ft_flags_num_1(&width, &prec, params, ft);
	if (width || prec)
	{
		if (width < 0)
			return (ft_flags_neg_width(ft, params, -width, prec));
		if (ft.ignore || ft.flag_minus)
			sym_count += ft_flags_num_14(params, ft, width, prec);
		else if (ft.flag_zero)
			sym_count += ft_flags_num_12(params, prec, ft, width);
		else
			sym_count += ft_flags_num_10(prec, width, params, ft);
	}
	else
		ft_flags_num_11(ft, prec, &sym_count, params);
	return (sym_count);
}
