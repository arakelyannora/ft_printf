/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 21:04:29 by narakely          #+#    #+#             */
/*   Updated: 2021/03/21 21:04:38 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int				arr[2];
	va_list			params;
	t_flags_types	flags_and_types;

	arr[0] = 0;
	va_start(params, format);
	while (*format != '\0')
	{
		while (*format != '%' && *format != '\0')
		{
			ft_putchar_fd(*format, 1);
			format++;
			arr[0]++;
		}
		if (*format == '%')
		{
			format++;
			flags_and_types = ft_initialize_struct(&format, &arr[0]);
			if ((arr[1] = ft_print(params, flags_and_types)) < 0)
				return (-1);
			arr[0] += arr[1];
		}
		va_end(params);
	}
	return (arr[0]);
}
