/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_to_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:55:05 by narakely          #+#    #+#             */
/*   Updated: 2021/03/21 18:55:12 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string_to_int(const char **format, int *n)
{
	int i;
	int j;
	int a;

	i = 0;
	j = 10;
	while (ft_isdigit((**format)))
	{
		a = (**format) - 48;
		*n = (*n) * j + a;
		(*format)++;
	}
}
