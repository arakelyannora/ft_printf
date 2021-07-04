/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:38:20 by narakely          #+#    #+#             */
/*   Updated: 2021/03/21 18:39:10 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_putpointer_2(char *s)
{
	int i;

	i = 0;
	while (s[i] == '0')
		i++;
	ft_putstr_fd("0x", 1);
	return (i);
}

void		ft_putpointer(void *pointer, t_flags_types ft, int neg_prec)
{
	long			p;
	int				i;
	char			s[2 * sizeof(p)];

	p = (long)pointer;
	i = (int)(2 * sizeof(p) - 1);
	if (!pointer && ft.prec_dot == 1 && neg_prec >= 0)
	{
		ft_putstr_fd("0x", 1);
		return ;
	}
	if (!pointer)
	{
		ft_putstr_fd("0x0", 1);
		return ;
	}
	while (i >= 0)
	{
		s[i--] = "0123456789ABCDEF"[p & 0x0F];
		p >>= 4;
	}
	i = ft_putpointer_2(s);
	while (i < (int)(2 * sizeof(p)))
		ft_putchar_fd(ft_tolower(s[i++]), 1);
}
