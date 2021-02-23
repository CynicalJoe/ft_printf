/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:38:18 by gtournay          #+#    #+#             */
/*   Updated: 2020/10/08 09:38:22 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*error(t_flags *param)
{
	param->error = 1;
	return (param);
}

t_flags	*free_error(t_flags *param)
{
	if (!param)
		return (NULL);
	if (param->buf)
		free(param->buf);
	param->buf = NULL;
	if (param->print)
		free(param->print);
	param->print = NULL;
	if (param)
		free(param);
	param = NULL;
	return (NULL);
}
