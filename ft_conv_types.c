/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:58:51 by narakely          #+#    #+#             */
/*   Updated: 2021/03/21 18:59:16 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_types(const char **format, t_flags_types *ft)
{
	if (**format == 'd' || **format == 'i')
		ft->type_di = 1;
	else if (**format == 's')
		ft->type_s = 1;
	else if (**format == 'c')
		ft->type_c = 1;
	else if (**format == 'p')
		ft->type_p = 1;
	else if (**format == 'u')
		ft->type_u = 1;
	else if (**format == 'x')
		ft->type_x = 1;
	else if (**format == 'X')
		ft->type_bigx = 1;
	else if (**format == '%')
		ft->type_percent = 1;
	else
		ft->error = 1;
	(*format)++;
}
