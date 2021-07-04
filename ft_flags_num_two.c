/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_num_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:47:09 by narakely          #+#    #+#             */
/*   Updated: 2021/03/24 20:47:13 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_flags_num_2(int width, int prec, int num, int *sym_count)
{
	if (width > prec)
		width -= prec;
	else
		width = 0;
	if (num < 0)
		width--;
	prec -= ft_num_length(num);
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num *= -1;
		(*sym_count)++;
	}
	while (prec-- > 0)
	{
		ft_putnbr_fd(0, 1);
		(*sym_count)++;
	}
	ft_putnbr_fd(num, 1);
	while (width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*sym_count)++;
	}
}

void			ft_flags_num_3(int prec, t_flags_types ft, int num)
{
	if (prec == 0 && ft.prec_dot == 1 && num == 0)
		ft_putchar_fd(' ', 1);
	else
		ft_putnbr_fd(num, 1);
}

int				ft_flags_num_4(int num, int width, int prec, t_flags_types ft)
{
	int sym_count;

	sym_count = 0;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num *= -1;
		sym_count++;
		width--;
	}
	width -= ft_num_length(num);
	ft_flags_num_3(prec, ft, num);
	while (width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		sym_count++;
	}
	return (sym_count);
}

void			ft_flags_num_13(int num, int *width, int *sym_count)
{
	if (num < 0)
	{
		(*width)--;
		(*sym_count)++;
	}
}

void			ft_flags_num_5(int width, int prec, int *sym_count, int num)
{
	if (width > prec)
		width -= prec;
	else
		width = 0;
	ft_flags_num_13(num, &width, sym_count);
	prec -= ft_num_length(num);
	while (width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*sym_count)++;
	}
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num *= -1;
	}
	while (prec-- > 0)
	{
		ft_putnbr_fd(0, 1);
		(*sym_count)++;
	}
	ft_putnbr_fd(num, 1);
}
