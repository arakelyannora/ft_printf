/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:39:27 by narakely          #+#    #+#             */
/*   Updated: 2021/03/24 15:39:29 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_flags_uns_1(int *width, int *prec,
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

static	void	ft_flags_uns_3(int width, int prec, int num, int *sym_count)
{
	if (width > prec)
		width -= prec;
	else
		width = 0;
	prec -= ft_uns_num_length(num);
	while (prec-- > 0)
	{
		ft_putuint_fd(0, 1);
		(*sym_count)++;
	}
	ft_putuint_fd(num, 1);
	while (width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*sym_count)++;
	}
}

int				ft_flags_uns_2(int width, int prec,
				va_list params, t_flags_types ft)
{
	int sym_count;
	int num;

	sym_count = 0;
	num = va_arg(params, int);
	if (width < 0)
		width *= -1;
	if (prec > (sym_count = ft_uns_num_length(num)))
		ft_flags_uns_3(width, prec, num, &sym_count);
	else
	{
		width -= ft_uns_num_length(num);
		if (prec == 0 && ft.prec_dot == 1 && num == 0)
			ft_putchar_fd(' ', 1);
		else
			ft_putuint_fd(num, 1);
		while (width-- > 0)
		{
			ft_putchar_fd(' ', 1);
			sym_count++;
		}
	}
	return (sym_count);
}

void			ft_flags_uns_5(int width, int prec,
				int num, int *sym_count)
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

int				ft_flags_unsigned_int(t_flags_types ft, va_list params)
{
	int prec;
	int width;
	int sym_count;
	int num;

	sym_count = 0;
	ft_flags_uns_1(&width, &prec, params, ft);
	if (width || prec)
	{
		if (ft.ignore || ft.flag_minus || width < 0)
			sym_count += ft_flags_uns_2(width, prec, params, ft);
		else if (ft.flag_zero)
			sym_count += ft_flags_uns_4(params, width, prec, ft);
		else
			sym_count += ft_flags_uns_6(prec, width, ft, params);
	}
	else
	{
		num = va_arg(params, int);
		sym_count = ft_uns_num_length(num);
		if (prec == 0 && ft.prec_dot && num == 0)
			return (0);
		ft_putuint_fd(num, 1);
	}
	return (sym_count);
}
