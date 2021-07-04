/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:42:23 by narakely          #+#    #+#             */
/*   Updated: 2021/03/21 17:54:40 by narakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_flags_types
{
	int flag_minus;
	int flag_zero;
	int prec_dot;
	int prec_dot_number;
	int prec_dot_ast;
	int width;
	int width_ast;
	int type_c;
	int type_s;
	int type_p;
	int type_di;
	int type_u;
	int type_x;
	int type_bigx;
	int type_percent;
	int error;
	int ignore;
}				t_flags_types;

void			ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char *s, int fd);
void			ft_putuint_fd(unsigned int n, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_isdigit(int arg);
int				ft_tolower(int arg);
void			ft_putpointer(void *pointer, t_flags_types ft, int neg_prec);
int				ft_strlen(const char *s);
void			ft_struct_zero(t_flags_types *flags_and_types);
void			ft_string_to_int(const char **format, int *n);
int				ft_check_on_errors(t_flags_types *ft);
void			ft_conv_types(const char **format, t_flags_types *ft);
int				ft_put_value_to_struct(const char **format,
				t_flags_types *flags_and_types, int *sym_count);
t_flags_types	ft_initialize_struct(const char **format, int *sym_count);
int				ft_flags_char(t_flags_types ft, va_list params);
int				ft_str_neg_width(char *s,
				t_flags_types ft, int width, int prec);
int				ft_flags_str(t_flags_types ft, va_list params);
int				ft_num_length(int num);
int				ft_uns_num_length(unsigned int num);
int				ft_flags_neg_width(t_flags_types ft, va_list params,
				int width, int prec);
int				ft_flags_num(t_flags_types ft, va_list params);
int				ft_flags_unsigned_int(t_flags_types ft, va_list params);
int				ft_putpointer_count(void *pointer,
				t_flags_types ft, int neg_prec);
int				ft_flags_pointer(t_flags_types ft, va_list params);
int				ft_flags_percent(t_flags_types ft, va_list params);
void			ft_putnbr_base_count(unsigned int nbr, char *base, int *count);
void			ft_putnbr_base(unsigned int nbr, char *base);
int				ft_flags_hex(t_flags_types ft, va_list params);
int				ft_print(va_list params, t_flags_types flags_and_types);
int				ft_printf(const char *format, ...);
int				ft_flags_str_1(int width, va_list params);
void			ft_flags_str_2(int width, int prec, int *sym_count, char *s);
void			ft_flags_str_3(int prec, char *s, int *sym_count);
void			ft_flags_str_4(int prec, char *s, int *sym_count, int width);
int				ft_flags_str_5(char *s, int width, int prec, t_flags_types ft);
void			ft_flags_str_6(t_flags_types ft,
				va_list params, int *width, int *prec);
void			ft_flags_str_7(va_list params, int *sym_count);
void			ft_flags_num_2(int width, int prec, int num, int *sym_count);
void			ft_flags_num_3(int prec, t_flags_types ft, int num);
int				ft_flags_num_4(int num, int width, int prec, t_flags_types ft);
void			ft_flags_num_13(int num, int *width, int *sym_count);
void			ft_flags_num_5(int width, int prec, int *sym_count, int num);
void			ft_flags_num_6(t_flags_types ft,
				int *sym_count, int prec, int *width);
void			ft_flags_num_7(int prec, t_flags_types ft, int *sym_count);
void			ft_flags_num_8(int width, int prec, int num, int *sym_count);
int				ft_flags_num_9(int num, int width, int prec, t_flags_types ft);
int				ft_flags_num_10(int prec, int width,
				va_list params, t_flags_types ft);
void			ft_flags_num_11(t_flags_types ft, int prec,
				int *sym_count, va_list params);
int				ft_flags_num_12(va_list params, int prec,
				t_flags_types ft, int width);
int				ft_flags_num_14(va_list params,
				t_flags_types ft, int width, int prec);
int				ft_flags_uns_2(int width, int prec,
				va_list params, t_flags_types ft);
void			ft_flags_uns_5(int width, int prec,
				int num, int *sym_count);
int				ft_flags_uns_6(int prec, int width,
				t_flags_types ft, va_list params);
int				ft_flags_uns_4(va_list params, int width,
				int prec, t_flags_types ft);
int				ft_flags_hex_3(int width, int prec, int num, t_flags_types ft);
void			ft_flags_hex_4(int *width, int *prec, int *sym_count);
int				ft_flags_hex_2(int width, int prec,
				va_list params, t_flags_types ft);
int				ft_flags_hex_6(int width, int prec, t_flags_types ft, int num);
void			ft_flags_hex_7(int prec, t_flags_types ft, int *sym_count);
int				ft_flags_hex_5(int width, int prec,
				va_list params, t_flags_types ft);
int				ft_flags_hex_9(int width, int prec, int num, t_flags_types ft);
int				ft_flags_hex_8(int width, int prec,
				t_flags_types ft, va_list params);
int				ft_flags_hex_10(int prec, int width,
				va_list params, t_flags_types ft);
#endif
