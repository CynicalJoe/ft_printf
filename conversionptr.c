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
	flag_hub(param);
	if (!(new_print = malloc(sizeof(char) *
	(ft_strlen(param->print) + ft_strlen(param->buf) + 1))))
		return (NULL);
	copy_start(param->print, new_print, param->index);
	copy_conv(param->buf, new_print, param->index, 0);
	i = param->index;
	while (param->print[i] != 'p')
		i++;
	i++;
	copy_conv(param->print, new_print, ft_strlen(new_print), i);
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
	flag_hub(param);
	if (!(new_print = malloc(sizeof(char) *
	(ft_strlen(param->print) + ft_strlen(param->buf) + 1))))
		return (NULL);
	copy_start(param->print, new_print, param->index);
	copy_conv(param->buf, new_print, param->index, 0);
	i = param->index;
	while (param->print[i] != 'x' && param->print[i] != 'X')
		i++;
	i++;
	copy_conv(param->print, new_print, ft_strlen(new_print), i);
	free(param->print);
	free(param->buf);
	param->print = new_print;
	return (param);
}

t_flags	*conversion_prct(t_flags *param)
{
	char	*new_print;
	char	*temp;
	size_t	i;

	if (!(temp = malloc(sizeof(char) * 2)))
		return (NULL);
	i = param->index;
	temp[0] = '%';
	temp[1] = '\0';
	param->buf = temp;
	flag_hub(param);
	if (!(new_print = malloc(sizeof(char) *
	(ft_strlen(param->print) + ft_strlen(param->buf) + 1))))
		return (NULL);
	copy_start(param->print, new_print, i);
	i++;
	copy_conv(param->buf, new_print, param->index, 0);
	while (param->print[i] != '%')
		i++;
	i++;
	copy_conv(param->print, new_print, ft_strlen(new_print), i);
	free(param->print);
	free(param->buf);
	param->print = new_print;
	return (param);
}
