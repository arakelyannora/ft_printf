/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns_num_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:49:58 by narakely          #+#    #+#             */
/*   Updated: 2021/03/21 20:50:06 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uns_num_length(unsigned int num)
{
	int length;

	length = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		length++;
		num /= 10;
	}
	return (length);
}
