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
	size_t i;

	i = param->index;
	if (!(param->buf = malloc(sizeof(char) * 2)))
		return (error(param));
	param->buf[0] = (char)va_arg(ap, int);
	param->buf[1] = '\0';
	if (!(flag_hub(param)))
		return (error(param));
	while (param->print[i] != 'c')
		i++;
	param->index = i;
	return (param);
}

t_flags	*conversion_int(t_flags *param, va_list ap)
{
	int		n;
	size_t	i;

	i = param->index;
	n = va_arg(ap, int);
	param->buf = ft_itoa(n);
	if (!(flag_hub(param)))
		return (error(param));
	while (param->print[i] != 'i' && param->print[i] != 'd')
		i++;
	param->index = i;
	return (param);
}

t_flags	*conversion_str(t_flags *param, va_list ap)
{
	char	*str;
	size_t	i;

	i = param->index;
	str = va_arg(ap, char*);
	param->buf = ft_strdup(str);
	if (!flag_hub(param))
		return (error(param));
	while (param->print[i] != 's')
		i++;
	param->index = i;
	return (param);
}

t_flags	*conversion_unsgnd(t_flags *param, va_list ap)
{
	unsigned int	n;
	size_t			i;

	n = va_arg(ap, unsigned int);
	param->buf = ft_untoa(n);
	if (!(flag_hub(param)))
		return (NULL);
	i = param->index;
	while (param->print[i] != 'u')
		i++;
	param->index = i;
	return (param);
}
