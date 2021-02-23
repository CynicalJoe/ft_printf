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
	/**if (param->is_term)
	{
		if (param->minus)
		{
			write(1, "\0", 1);
		}
		param->len++;
	}**/
	while (param->print[param->len])
	{
		write(1, &param->print[param->len], 1);
		param->len++;
	}
	if (param->is_term)
	{
		if (!param->minus)
			write(1, "\0", 1);
	}
	return (param);
}
