/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_str_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:10:59 by narakely          #+#    #+#             */
/*   Updated: 2021/03/24 16:44:48 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flags_str_5(char *s, int width, int prec, t_flags_types ft)
{
	int sym_count;

	sym_count = 0;
	if (prec > ft_strlen(s) || !prec)
		width -= ft_strlen(s);
	else if (prec > 0)
		width -= prec;
	else
		width += prec + 1;
	if (!ft.flag_minus)
		ft_flags_str_2(width, prec, &sym_count, s);
	else
		ft_flags_str_4(prec, s, &sym_count, width);
	return (sym_count);
}

void	ft_flags_str_6(t_flags_types ft, va_list params, int *width, int *prec)
{
	if (ft.prec_dot_number)
		*prec = ft.prec_dot_number;
	if (ft.width_ast)
		*width = va_arg(params, int);
	if (ft.prec_dot_ast)
		*prec = va_arg(params, int);
	if (ft.width)
		*width = ft.width;
}

void	ft_flags_str_7(va_list params, int *sym_count)
{
	char *s;

	if (!(s = va_arg(params, char*)))
		*sym_count = ft_putstr_fd("(null)", 1);
	else
		*sym_count = ft_putstr_fd(s, 1);
}
