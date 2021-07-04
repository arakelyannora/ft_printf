/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:45:46 by narakely          #+#    #+#             */
/*   Updated: 2021/03/21 18:46:18 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_struct_zero(t_flags_types *flags_and_types)
{
	flags_and_types->prec_dot = 0;
	flags_and_types->prec_dot_ast = 0;
	flags_and_types->prec_dot_number = 0;
	flags_and_types->flag_minus = 0;
	flags_and_types->flag_zero = 0;
	flags_and_types->width = 0;
	flags_and_types->width_ast = 0;
	flags_and_types->type_bigx = 0;
	flags_and_types->type_c = 0;
	flags_and_types->type_di = 0;
	flags_and_types->type_p = 0;
	flags_and_types->type_s = 0;
	flags_and_types->type_u = 0;
	flags_and_types->type_x = 0;
	flags_and_types->type_percent = 0;
	flags_and_types->error = 0;
	flags_and_types->ignore = 0;
}
