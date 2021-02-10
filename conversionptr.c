/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversionptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:38:18 by gtournay          #+#    #+#             */
/*   Updated: 2020/10/08 09:38:22 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*conversion_ptr(t_flags *param, va_list ap)
{
	char				*new_print;
	unsigned long int	*n;
	unsigned long int	adr;
	size_t				i;

	n = va_arg(ap, void*);
	adr = (unsigned long int)n;
	param->buf = adr_frmt(hex_conv(adr, "0123456789abcdef"));
	if (!flag_hub(param))
		return (error(param));
	if (!(new_print = malloc(sizeof(char) *
	(ft_strlen(param->print) + ft_strlen(param->buf) + 1))))
		return (error(param));
	copy_start(param->print, new_print, param->index);
	copy_conv(param->buf, new_print, param->index, 0);
	i = param->index;
	while (param->print[i] != 'p')
		i++;
	copy_conv(param->print, new_print, ft_strlen(new_print), i + 1);
	free(param->print);
	free(param->buf);
	param->print = new_print;
	return (param);
}

t_flags	*conversion_hexa(t_flags *param, va_list ap)
{
	char			*new_print;
	unsigned int	n;
	size_t			i;

	n = va_arg(ap, unsigned int);
	if (param->conv_type == 'x')
		param->buf = hex_clean(hex_conv(n, "0123456789abcdef"));
	else
		param->buf = hex_clean(hex_conv(n, "0123456789ABCDEF"));
	if (!flag_hub(param))
		return (error(param));
	if (!(new_print = malloc(sizeof(char) *
	(ft_strlen(param->print) + ft_strlen(param->buf) + 1))))
		return (error(param));
	copy_start(param->print, new_print, param->index);
	copy_conv(param->buf, new_print, param->index, 0);
	i = param->index;
	while (param->print[i] != 'x' && param->print[i] != 'X')
		i++;
	copy_conv(param->print, new_print, ft_strlen(new_print), i + 1);
	free(param->print);
	free(param->buf);
	param->print = new_print;
	return (param);
}

t_flags	*conversion_prct(t_flags *param)
{
	char	*new_print;
	size_t	i;

	if (!(param->buf = malloc(sizeof(char) * 2)))
		return (error(param));
	i = param->index;
	param->buf[0] = '%';
	param->buf[1] = '\0';
	if (!flag_hub(param))
		return (error(param));
	if (!(new_print = malloc(sizeof(char) *
	(ft_strlen(param->print) + ft_strlen(param->buf) + 1))))
		return (error(param));
	copy_start(param->print, new_print, i);
	i++;
	copy_conv(param->buf, new_print, param->index, 0);
	while (param->print[i] != '%')
		i++;
	copy_conv(param->print, new_print, ft_strlen(new_print), i + 1);
	free(param->print);
	free(param->buf);
	param->print = new_print;
	return (param);
}
