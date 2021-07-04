/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:55:37 by narakely          #+#    #+#             */
/*   Updated: 2021/03/21 20:55:50 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_putpointer_count_2(char *s)
{
	int i;

	i = 0;
	while (s[i] == '0')
		i++;
	return (i);
}

int			ft_putpointer_count(void *pointer, t_flags_types ft, int neg_prec)
{
	long	p;
	int		i;
	int		count;
	char	s[2 * sizeof(p)];

	count = 2;
	p = (long)pointer;
	i = (int)(2 * sizeof(p) - 1);
	if (!pointer && ft.prec_dot == 1 && neg_prec >= 0)
		return (2);
	if (!pointer)
		return (3);
	while (i >= 0)
	{
		s[i--] = "0123456789ABCDEF"[p & 0x0F];
		p >>= 4;
	}
	i = ft_putpointer_count_2(s);
	while (i < (int)(2 * sizeof(p)))
	{
		i++;
		count++;
	}
	return (count);
}
