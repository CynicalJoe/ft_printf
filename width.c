/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:38:18 by gtournay          #+#    #+#             */
/*   Updated: 2020/10/08 09:38:22 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*wdth_left(t_flags *param, char c)
{
	char	*new;
	size_t	i;
	size_t	len;

	len = ft_strlen(param->buf);
	i = 0;
	if (!(new = malloc(sizeof(char) * (param->minwidth + len + 1))))
		return (error(param));
	if (is_in_set(param->conv_type, "id") && c == '0' && param->buf[0] == '-' && len < param->minwidth)
	{
		new[i++] = '-';
		param->buf[0] = '0';
	}
	while (i + len < param->minwidth)
		new[i++] = c;
	len = 0;
	while (param->buf[len])
		new[i++] = param->buf[len++];
	new[i] = '\0';
	free(param->buf);
	param->buf = new;
	return (param);
}

t_flags	*wdth_right(t_flags *param)
{
	char	*new;
	size_t	i;

	if (!(new = malloc(sizeof(char) *
	(param->minwidth + ft_strlen(param->buf) + 1))))
		return (error(param));
	i = 0;
	while (param->buf[i])
	{
		new[i] = param->buf[i];
		i++;
	}
	while (i < param->minwidth)
	{
		new[i] = ' ';
		i++;
	}
	new[i] = '\0';
	free(param->buf);
	param->buf = new;
	return (param);
}

t_flags	*get_width(t_flags *param)
{
	size_t i;

	if (!param->print)
		return (param);
	i = param->index + 1;
	while (param->print[i] && (param->print[i] == '0' || param->print[i] == '-'))
		i++;
	if (ft_isdigit(param->print[i]))
	{
		if (!param->minwidth)
			param->minwidth = ft_atoi(&param->print[i]);
	}
	while (!is_in_set(param->print[i], "cspdiuxX%.") && param->print[i])
		i++;
	if (param->print[i] && param->print[i] == '.')
		i++;
	if (ft_isdigit(param->print[i]))
	{
		if (!param->maxwidth)
			param->maxwidth = ft_atoi(&param->print[i]);
	}
	return (param);
}
