/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:57:21 by narakely          #+#    #+#             */
/*   Updated: 2021/03/21 20:57:26 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_count(unsigned int nbr, char *base, int *count)
{
	unsigned int b;

	b = (unsigned int)ft_strlen(base);
	if (nbr < b)
		(*count)++;
	else
	{
		ft_putnbr_base_count(nbr / b, base, count);
		ft_putnbr_base_count(nbr % b, base, count);
	}
}
