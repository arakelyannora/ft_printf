/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:49:14 by narakely          #+#    #+#             */
/*   Updated: 2021/03/21 19:49:29 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_flags_char_two(int width, t_flags_types ft, va_list params)
{
	if (ft.flag_minus || width < 0)
	{
		if (width < 0)
			width *= -1;
		ft_putchar_fd(va_arg(params, unsigned int), 1);
		while (width - 1)
		{
			ft_putchar_fd(' ', 1);
			width--;
		}
	}
	else
	{
		while (width - 1)
		{
			ft_putchar_fd(' ', 1);
			width--;
		}
		ft_putchar_fd(va_arg(params, unsigned int), 1);
	}
}

int				ft_flags_char(t_flags_types ft, va_list params)
{
	int sym_count;
	int width;

	sym_count = 1;
	width = 0;
	if (ft.width_ast)
	{
		width = va_arg(params, int);
		sym_count = width == 0 ? 1 : width;
		if (width < 0)
			sym_count *= -1;
	}
	if (ft.width)
	{
		width = ft.width;
		sym_count = width;
	}
	if (width)
		ft_flags_char_two(width, ft, params);
	else
		ft_putchar_fd(va_arg(params, unsigned int), 1);
	return (sym_count);
}
