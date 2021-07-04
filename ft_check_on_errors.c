/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_on_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 18:56:47 by narakely          #+#    #+#             */
/*   Updated: 2021/03/21 18:57:18 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_on_errors(t_flags_types *ft)
{
	if (ft->error)
		return (0);
	if (!ft->type_c && !ft->type_di && !ft->type_p && !ft->type_percent
		&& !ft->type_s && !ft->type_u && !ft->type_x && !ft->type_bigx)
		return (0);
	if (ft->flag_minus && ft->flag_zero)
		ft->ignore = 1;
	return (1);
}
