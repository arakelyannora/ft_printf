/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_neg_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:20:55 by narakely          #+#    #+#             */
/*   Updated: 2021/03/21 20:21:05 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_str_neg_width_two(char **s, int width,
				int prec, int *sym_count)
{
	if (prec > 0)
	{
		while (prec-- > 0 && **s != '\0')
		{
			ft_putchar_fd(**s, 1);
			(*s)++;
			(*sym_count)++;
		}
	}
	else
	{
		while (**s != '\0')
		{
			ft_putchar_fd(**s, 1);
			(*s)++;
			(*sym_count)++;
		}
	}
	while (width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*sym_count)++;
	}
}

int				ft_str_neg_width(char *s, t_flags_types ft, int width, int prec)
{
	int sym_count;

	sym_count = 0;
	if (prec > ft_strlen(s) || !prec || ft.flag_minus)
		width -= ft_strlen(s);
	else if (prec > 0)
		width -= prec;
	else
		width += prec + 1;
	ft_str_neg_width_two(&s, width, prec, &sym_count);
	return (sym_count);
}
