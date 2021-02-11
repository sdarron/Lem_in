/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define FLG_NONE   0b00000000
# define FLG_MINUS  0b00000001
# define FLG_PLUS   0b00000010
# define FLG_SPACE  0b00000100
# define FLG_HASH   0b00001000
# define FLG_ZERO   0b00010000
# define SIZE_NONE  0
# define SIZE_H     1
# define SIZE_HH    2
# define SIZE_L     3
# define SIZE_LL    4
# define SIZE_LB    5

typedef	struct
{
	unsigned char	flags;
	int				is_width;
	long long int	width;
	int				is_precision;
	long long int	precision;
	char			type;
	int				size;
	int				char_zero;
}					t_format;

int					ft_printf(const char *line, ...);
t_format			parser(int *k, const char *line, va_list *ap);
void				init(t_format *form);
int					is_there_any_flag(const int i, const char *line);
void				add_flag(char c, t_format *res);
char				*processor(t_format *form, va_list *ap);
void				finish_str(char *str, va_list *ap);
void				finish(va_list *ap);
char				*zero_string(va_list *ap);
char				*add_precision_int(char *str, long unsigned int k,
					va_list *ap);
char				*add_width_int_right(char *str, char *result,
					long unsigned int len);
char				*add_width_int(char *str, t_format form, va_list *ap);
char				*add_width_int_left(char *str, char *result,
					long unsigned int len, long unsigned int flags);
char				*add_sign_int(char *str, char c, va_list *ap);
char				*add_space_int(char *str, va_list *ap);
char				*processor_int(t_format *form, va_list *ap);
char				*processor_u(t_format *form, va_list *ap);
char				*add_alternative_form_x(char *str, va_list *ap);
char				*processor_x(t_format *form, va_list *ap);
char				*processor_xx(t_format *form, va_list *ap);
char				*processor_o(t_format *form, va_list *ap);
char				*add_width_string_left(char *result, char *str,
					unsigned int len);
char				*add_width_string_right(char *result, char *str,
					unsigned int len);
char				*add_width_string(char *str, t_format form,
					va_list *ap);
char				*add_precision_string(char *str, unsigned int len,
					va_list *ap);
char				*processor_string(t_format *form, va_list *ap);
char				*processor_char(t_format *form, va_list *ap);
char				*processor_p(t_format *form, va_list *ap);
char				*processor_f(t_format *form, va_list *ap);
char				*add_digit(char *str, va_list *ap);
char				*add_round(char *str, va_list *ap);
char				*add_point(char *str, va_list *ap);

#endif
