/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:58:46 by narakely          #+#    #+#             */
/*   Updated: 2021/03/21 21:00:12 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int b;

	b = (unsigned int)ft_strlen(base);
	if (nbr < b)
		write(1, &base[nbr], 1);
	else
	{
		ft_putnbr_base(nbr / b, base);
		ft_putnbr_base(nbr % b, base);
	}
}
