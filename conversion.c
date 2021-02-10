/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:38:18 by gtournay          #+#    #+#             */
/*   Updated: 2020/10/08 09:38:22 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*conversion_char(t_flags *param, va_list ap)
{
	size_t	i;
	size_t	j;
	char	*new_print;

	if (!(param->buf = malloc(sizeof(char) * 2)))
		return (NULL);
	param->buf[0] = (char)va_arg(ap, int);
	param->buf[1] = '\0';
	flag_hub(param);
	if (!(new_print = (char*)malloc(sizeof(char) *
	(ft_strlen(param->print) + ft_strlen(param->buf) + 1))))
		return (NULL);
	copy_start(param->print, new_print, param->index);
	i = param->index;
	copy_conv(param->buf, new_print, i, 0);
	j = i + ft_strlen(param->buf);
	while (param->print[i] != 'c')
		i++;
	i++;
	copy_conv(param->print, new_print, j, i);
	free(param->print);
	param->print = new_print;
	return (param);
}

t_flags	*conversion_int(t_flags *param, va_list ap)
{
	int		n;
	size_t	i;
	size_t	j;
	char	*new_print;

	n = va_arg(ap, int);
	param->buf = ft_itoa(n);
	flag_hub(param);
	if (!(new_print = (char*)malloc(sizeof(char) *
	(ft_strlen(param->print) + ft_strlen(param->buf) + 1))))
		return (NULL);
	copy_start(param->print, new_print, param->index);
	i = param->index;
	copy_conv(param->buf, new_print, i, 0);
	j = i + ft_strlen(param->buf);
	while (param->print[i] != 'd' && param->print[i] != 'i')
		i++;
	i++;
	copy_conv(param->print, new_print, j, i);
	free(param->print);
	free(param->buf);
	param->print = new_print;
	return (param);
}

t_flags	*conversion_str(t_flags *param, va_list ap)
{
	size_t	i;
	size_t	j;
	char	*new_print;
	char	*str;

	str = va_arg(ap, char*);
	param->buf = ft_strdup(str);
	flag_hub(param);
	if (!(new_print = (char*)malloc(sizeof(char) *
	(ft_strlen(param->print) + ft_strlen(param->buf) + 1))))
		return (NULL);
	copy_start(param->print, new_print, param->index);
	i = param->index;
	copy_conv(param->buf, new_print, i, 0);
	j = ft_strlen(new_print);
	while (param->print[i] != 's')
		i++;
	i++;
	copy_conv(param->print, new_print, j, i);
	free(param->print);
	free(param->buf);
	param->print = new_print;
	return (param);
}

t_flags	*conversion_unsgnd(t_flags *param, va_list ap)
{
	unsigned int	n;
	size_t			i;
	size_t			j;
	char			*new_print;

	n = va_arg(ap, unsigned int);
	param->buf = ft_untoa(n);
	flag_hub(param);
	if (!(new_print = (char*)malloc(sizeof(char) *
	(ft_strlen(param->print) + ft_strlen(param->buf) + 1))))
		return (NULL);
	copy_start(param->print, new_print, param->index);
	i = param->index;
	copy_conv(param->buf, new_print, i, 0);
	j = i + ft_strlen(param->buf);
	while (param->print[i] != 'u')
		i++;
	i++;
	copy_conv(param->print, new_print, j, i);
	free(param->print);
	free(param->buf);
	param->print = new_print;
	return (param);
}
