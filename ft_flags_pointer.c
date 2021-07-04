/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:40:19 by narakely          #+#    #+#             */
/*   Updated: 2021/03/24 15:40:20 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_flags_pointer_1(int *width, int *prec,
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

static	void	ft_flags_pointer_2(int width, va_list params,
				int *sym_count, t_flags_types ft)
{
	void *p;

	if (width < 0)
		width *= -1;
	ft_putpointer(p = va_arg(params, void*), ft, 0);
	*sym_count = ft_putpointer_count(p, ft, 0);
	width -= *sym_count;
	while (width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*sym_count)++;
	}
}

static	void	ft_flags_pointer_3(int width, va_list params,
				int *sym_count, t_flags_types ft)
{
	void *p;

	p = va_arg(params, void*);
	*sym_count = ft_putpointer_count(p, ft, 0);
	width -= *sym_count;
	while (width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*sym_count)++;
	}
	ft_putpointer(p, ft, 0);
}

int				ft_flags_pointer(t_flags_types ft, va_list params)
{
	int		width;
	int		prec;
	int		sym_count;
	void	*p;
	int		neg_prec;

	sym_count = 0;
	ft_flags_pointer_1(&width, &prec, params, ft);
	neg_prec = prec < 0 ? -1 : prec;
	if (width)
	{
		if (ft.flag_minus || width < 0)
			ft_flags_pointer_2(width, params, &sym_count, ft);
		else
			ft_flags_pointer_3(width, params, &sym_count, ft);
	}
	else
	{
		ft_putpointer(p = va_arg(params, void*), ft, neg_prec);
		sym_count = ft_putpointer_count(p, ft, neg_prec);
	}
	return (sym_count);
}
