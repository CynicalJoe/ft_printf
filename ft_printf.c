/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:38:18 by gtournay          #+#    #+#             */
/*   Updated: 2020/10/08 09:38:22 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*conversion_hub(t_flags *param, va_list ap)
{
	check_conversion(param, ap);
	while (param->conver)
	{
		if (param->conv_type == 'd' || param->conv_type == 'i')
			conversion_int(param, ap);
		if (param->conv_type == 'c')
			conversion_char(param, ap);
		if (param->conv_type == 's')
			conversion_str(param, ap);
		if (param->conv_type == 'p')
			conversion_ptr(param, ap);
		if (param->conv_type == 'u')
			conversion_unsgnd(param, ap);
		if (param->conv_type == 'x' || param->conv_type == 'X')
			conversion_hexa(param, ap);
		if (param->conv_type == '%')
			conversion_prct(param);
		writer(param);
		check_conversion(param, ap);
		if (param->error)
			return (free_error(param));
	}
	return (param);
}

int		ft_printf(const char *format, ...)
{
	size_t	len;
	t_flags	*param;
	va_list	ap;

	if (!(param = initialize(format)))
		return (-1);
	va_start(ap, format);
	if (!(conversion_hub(param, ap)))
	{
		va_end(ap);
		return (-1);
	}
	writer(param);
	len = param->len;
	va_end(ap);
	free(param->print);
	free(param);
	return (len);
}
