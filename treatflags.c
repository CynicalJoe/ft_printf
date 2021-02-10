/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:38:18 by gtournay          #+#    #+#             */
/*   Updated: 2020/10/08 09:38:22 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*max_width_zero(t_flags *param, char *new, size_t index)
{
	if (param->maxwidth == 0)
		new[index] = ' ';
	return (new);
}

t_flags	*flag_hub(t_flags *param)
{
	if (param->error || !param->buf)
		return (NULL);
	if (param->point == 1)
		treat_prec(param);
	else if (!param->error)
	{
		get_width(param);
		if (param->minus && !param->error)
			wdth_right(param);
		else
		{
			if (param->zero && param->star && !param->error)
				wdth_left(param, '0');
			else if (!param->error)
				wdth_left(param, ' ');
		}
	}
	if (param->error)
		return (NULL);
	return (param);
}

t_flags	*nbr_prec(t_flags *param)
{
	char	*new;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(param->buf);
	if (!(new = malloc(sizeof(char) * (len + param->maxwidth + 1))))
		return (error(param));
	if (param->buf[i] == '-')
	{
		new[i++] = '-';
		len--;
		param->maxwidth++;
	}
	while (i + len < param->maxwidth)
		new[i++] = '0';
	len = 0;
	if (param->buf[len] == '-')
		len++;
	while (param->buf[len])
		new[i++] = param->buf[len++];
	new = max_width_zero(param, new, i - 1);
	new[i] = '\0';
	free(param->buf);
	param->buf = new;
	return (param);
}

t_flags	*treat_prec(t_flags *param)
{
	get_width(param);
	if (param->conv_type == 's')
		param->buf[param->maxwidth] = '\0';
	if (is_in_set(param->conv_type, "diuxX"))
		nbr_prec(param);
	if (param->minus && !param->error)
		wdth_right(param);
	else if (!param->error)
	{
		if (param->zero && param->star)
			wdth_left(param, '0');
		else
			wdth_left(param, ' ');
	}
	return (param);
}

int		is_in_set(char c, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}
