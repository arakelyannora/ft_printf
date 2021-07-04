/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:41:29 by narakely          #+#    #+#             */
/*   Updated: 2021/03/21 20:41:46 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flags_str_1(int width, va_list params)
{
	int sym_count;

	sym_count = 0;
	if (width)
	{
		sym_count = width;
		while (width--)
			ft_putchar_fd(' ', 1);
	}
	va_arg(params, char*);
	return (sym_count);
}

void	ft_flags_str_3(int prec, char *s, int *sym_count)
{
	if (prec < 0)
	{
		while (*s != '\0')
		{
			ft_putchar_fd(*s, 1);
			s++;
			(*sym_count)++;
		}
	}
	else
	{
		while (prec-- > 0 && *s != '\0')
		{
			ft_putchar_fd(*s, 1);
			s++;
			(*sym_count)++;
		}
	}
}

void	ft_flags_str_2(int width, int prec, int *sym_count, char *s)
{
	while (width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*sym_count)++;
	}
	if (!prec)
	{
		while (*s != '\0')
		{
			ft_putchar_fd(*s, 1);
			s++;
			(*sym_count)++;
		}
	}
	else
		ft_flags_str_3(prec, s, sym_count);
}

void	ft_flags_str_4(int prec, char *s, int *sym_count, int width)
{
	if (prec)
	{
		while (prec-- > 0 && *s != '\0')
		{
			ft_putchar_fd(*s, 1);
			s++;
			(*sym_count)++;
		}
	}
	else
	{
		while (*s != '\0')
		{
			ft_putchar_fd(*s, 1);
			s++;
			(*sym_count)++;
		}
	}
	while (width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*sym_count)++;
	}
}

int		ft_flags_str(t_flags_types ft, va_list params)
{
	int		prec;
	int		width;
	int		sym_count;
	char	*s;

	width = 0;
	prec = 0;
	sym_count = 0;
	ft_flags_str_6(ft, params, &width, &prec);
	if (ft.prec_dot && prec == 0)
		return (ft_flags_str_1(width, params));
	if (width != 0 || prec != 0)
	{
		s = va_arg(params, char*);
		if (!s)
			s = "(null)";
		if (width < 0)
			return (ft_str_neg_width(s, ft, -width, prec));
		else
			sym_count += ft_flags_str_5(s, width, prec, ft);
	}
	else
		ft_flags_str_7(params, &sym_count);
	return (sym_count);
}
