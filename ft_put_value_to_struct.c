/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_value_to_struct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:16:53 by narakely          #+#    #+#             */
/*   Updated: 2021/03/21 19:17:06 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_norm(const char **f, t_flags_types *ft)
{
	if (**f == '-')
		ft->flag_minus = 1;
	if (**f == '0' && !ft->flag_zero && !ft->prec_dot)
		ft->flag_zero = 1;
	if (**f == '.')
		ft->prec_dot = 1;
	if (**f == '*' && !ft->prec_dot && !ft->width_ast)
		ft->width_ast = 1;
	else if (**f == '*' && ft->prec_dot && !ft->prec_dot_ast)
		ft->prec_dot_ast = 1;
	else if ((**f == '*' && ft->prec_dot && ft->prec_dot_ast &&
		ft->width_ast && ft->prec_dot_ast)
		|| (**f == '*' && ft->width_ast && !ft->prec_dot_ast))
		ft->error = 1;
}

static	void	ft_norm_two(const char **f, int *sym_count)
{
	if (**f == ' ')
	{
		ft_putchar_fd(' ', 1);
		(*sym_count)++;
		while (**f == ' ')
			(*f)++;
	}
	else
		(*f)++;
}

int				ft_put_value_to_struct(const char **f,
			t_flags_types *ft, int *sym_count)
{
	while (**f != 'c' && **f != 's' && **f != 'p' && **f != 'd' && **f != 'i'
	&& **f != 'u' && **f != 'x' && **f != 'X' && **f != '%' && **f != '\0')
	{
		ft_norm(f, ft);
		if (**f && ft_isdigit(**f) && !ft->prec_dot)
		{
			ft_string_to_int(f, &(ft->width));
			continue ;
		}
		if (**f && ft_isdigit(**f) && ft->prec_dot)
		{
			ft_string_to_int(f, &(ft->prec_dot_number));
			continue ;
		}
		ft_norm_two(f, sym_count);
	}
	ft_conv_types(f, ft);
	return (ft_check_on_errors(ft));
}
