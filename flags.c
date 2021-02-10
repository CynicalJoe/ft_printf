/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:38:18 by gtournay          #+#    #+#             */
/*   Updated: 2020/10/08 09:38:22 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*handle_star(t_flags *param, va_list ap)
{
	int temp;

	temp = va_arg(ap, int);
	if (temp < 0)
		temp = -temp;
	if (param->star == 1)
		param->maxwidth = (size_t)temp;
	else
		param->minwidth = (size_t)temp;
	return (param);
}

t_flags	*initialize(char const *format)
{
	t_flags	*param;

	if (!format)
		return (NULL);
	if (!(param = malloc(sizeof(t_flags))))
		return (NULL);
	if (!(param->print = ft_strdup(format)))
		return (free_error(param));
	param->buf = NULL;
	param->conver = 0;
	param->index = 0;
	param->len = 0;
	param->error = 0;
	param->is_term = 0;
	param->conv_type = 0;
	param->zero = 0;
	param->star = 0;
	param->point = 0;
	param->minus = 0;
	param->minwidth = 0;
	param->maxwidth = 0;
	return (param);
}

t_flags	*reset_flags(t_flags *param)
{
	param->buf = NULL;
	param->conver = 0;
	param->zero = 0;
	param->star = 0;
	param->point = 0;
	param->minus = 0;
	param->minwidth = 0;
	param->maxwidth = 0;
	return (param);
}

t_flags	*check_conversion(t_flags *param, va_list ap)
{
	size_t	i;

	reset_flags(param);
	i = param->index;
	if (param->conv_type == '%')
	{
		while (param->print[i] != '%')
			i++;
		i++;
	}
	else if (param->index)
		i++;
	while (param->print[i])
	{
		if (param->print[i] == '%')
		{
			param->conver = 1;
			param->index = i;
			break ;
		}
		i++;
	}
	check_flags(param, ap);
	return (param);
}

t_flags	*check_flags(t_flags *param, va_list ap)
{
	size_t i;

	i = param->index + 1;
	if (param->conver)
	{
		while (param->print[i] && !is_in_set(param->print[i], "%cspdiuxX"))
		{
			if (param->print[i] == '0')
				param->zero = 1;
			else if (param->print[i] == '-')
				param->minus = 1;
			else if (param->print[i] == '.')
				param->point = 1;
			else if (param->print[i] == '*')
			{
				handle_star(param, ap);
				param->star = 1;
			}
			i++;
		}
		if (!param->print[i])
			return (error(param));
		param->conv_type = param->print[i];
	}
	return (param);
}
