/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 21:01:45 by narakely          #+#    #+#             */
/*   Updated: 2021/03/21 21:01:54 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(va_list params, t_flags_types flags_and_types)
{
	int sym_count;

	sym_count = 0;
	if (!ft_check_on_errors(&flags_and_types))
		return (-1);
	if (flags_and_types.type_c)
		sym_count = ft_flags_char(flags_and_types, params);
	if (flags_and_types.type_s)
		sym_count = ft_flags_str(flags_and_types, params);
	if (flags_and_types.type_di)
		sym_count = ft_flags_num(flags_and_types, params);
	if (flags_and_types.type_u)
		sym_count = ft_flags_unsigned_int(flags_and_types, params);
	if (flags_and_types.type_p)
		sym_count = ft_flags_pointer(flags_and_types, params);
	if (flags_and_types.type_percent)
		sym_count = ft_flags_percent(flags_and_types, params);
	if (flags_and_types.type_bigx || flags_and_types.type_x)
		sym_count = ft_flags_hex(flags_and_types, params);
	return (sym_count);
}
