/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:44:37 by narakely          #+#    #+#             */
/*   Updated: 2021/03/21 19:44:49 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags_types	ft_initialize_struct(const char **format, int *sym_count)
{
	t_flags_types flags_and_types;

	ft_struct_zero(&flags_and_types);
	ft_put_value_to_struct(format, &flags_and_types, sym_count);
	return (flags_and_types);
}
