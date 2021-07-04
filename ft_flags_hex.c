/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:42:16 by narakely          #+#    #+#             */
/*   Updated: 2021/03/24 15:42:19 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_flags_hex_1(int *width, int *prec,
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

int				ft_flags_hex(t_flags_types ft, va_list params)
{
	int prec;
	int width;
	int sym_count;
	int num;

	sym_count = 0;
	ft_flags_hex_1(&width, &prec, params, ft);
	if (width || prec)
		sym_count = ft_flags_hex_10(prec, width, params, ft);
	else
	{
		num = va_arg(params, int);
		ft_putnbr_base_count(num, ft.type_bigx ? "0123456789ABCDEF" :
							"0123456789abcdef", &sym_count);
		if (prec == 0 && ft.prec_dot && num == 0)
			return (0);
		ft_putnbr_base(num, ft.type_bigx ? "0123456789ABCDEF" :
						"0123456789abcdef");
	}
	return (sym_count);
}
