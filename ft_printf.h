/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:35:28 by gtournay          #+#    #+#             */
/*   Updated: 2020/10/08 09:36:38 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_flags
{
	char				*print;
	char				*buf;
	char				conv_type;
	int					conver;
	int					error;
	int					zero;
	int					star;
	int					point;
	int					minus;
	int					len;
	int					is_term;
	size_t				index;
	size_t				minwidth;
	size_t				maxwidth;

}				t_flags;

int				ft_printf(const char *format, ...);

int				is_in_set(char c, char *str);

char			*ft_untoa(unsigned int n);

char			*hex_conv(unsigned long int n, char *base);

char			*adr_frmt(char *hexa);

char			*hex_clean(char *hexa);

t_flags			*conversion_char(t_flags *param, va_list ap);

t_flags			*conversion_int(t_flags *param, va_list ap);

t_flags			*conversion_str(t_flags *param, va_list ap);

t_flags			*conversion_ptr(t_flags *param, va_list ap);

t_flags			*conversion_unsgnd(t_flags *param, va_list ap);

t_flags			*conversion_hexa(t_flags *param, va_list ap);

t_flags			*conversion_prct(t_flags *param);

t_flags			*initialize(char const *format);

t_flags			*check_conversion(t_flags *param, va_list ap);

t_flags			*check_flags(t_flags *param, va_list ap);

t_flags			*reset_flags(t_flags *param);

t_flags			*flag_hub(t_flags *param);

t_flags			*treat_prec(t_flags *param);

t_flags			*get_width(t_flags *param);

t_flags			*wdth_left(t_flags *param, char c);

t_flags			*wdth_right(t_flags *param);

t_flags			*nbr_prec(t_flags *param);

t_flags			*free_error(t_flags *param);

t_flags			*error(t_flags *param);

t_flags			*writer(t_flags *param);

t_flags			*initial_write(t_flags *param);

#endif
