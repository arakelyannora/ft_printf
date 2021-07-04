/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:41:12 by narakely          #+#    #+#             */
/*   Updated: 2021/03/24 15:41:13 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_flags_percent_1(int *width, int *prec,
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

static	void	ft_flags_percent_2(char c, int width, int x)
{
	if (x == 1)
	{
		while (width - 1)
		{
			ft_putchar_fd(c, 1);
			width--;
		}
		ft_putchar_fd('%', 1);
	}
	else
	{
		ft_putchar_fd('%', 1);
		while (width - 1)
		{
			ft_putchar_fd(c, 1);
			width--;
		}
	}
}

int				ft_flags_percent(t_flags_types ft, va_list params)
{
	int prec;
	int width;
	int sym_count;

	sym_count = 0;
	ft_flags_percent_1(&width, &prec, params, ft);
	if (width)
	{
		sym_count = width;
		if (ft.flag_minus)
			ft_flags_percent_2(' ', width, 0);
		else if (ft.flag_zero)
			ft_flags_percent_2('0', width, 1);
		else
			ft_flags_percent_2(' ', width, 1);
	}
	else
	{
		ft_putchar_fd('%', 1);
		sym_count = 1;
	}
	return (sym_count);
}
