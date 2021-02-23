/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:38:18 by gtournay          #+#    #+#             */
/*   Updated: 2020/10/08 09:38:22 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*writer(t_flags *param)
{
	size_t i;

	i = 0;
	if (!param->buf)
		return (param);
	if (param->is_term)
	{
		if (param->minus)
			write(1, "\0", 1);
		param->len++;
	}
	while (param->buf[i])
	{
		write(1, &param->buf[i++], 1);
		param->len++;
	}
	if (param->is_term)
	{
		if (!param->minus)
			write(1, "\0", 1);
	}
	free(param->buf);
	return (param);
}

t_flags	*initial_write(t_flags *param)
{
	size_t i;

	i = param->index;
	if (param->index)
		i++;
	while (param->print[i] && param->print[i] != '%')
	{
		write(1, &param->print[i++], 1);
		param->len++;
	}
	return (param);
}
