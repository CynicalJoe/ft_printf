/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <gtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:36:10 by gtournay          #+#    #+#             */
/*   Updated: 2020/09/12 13:06:00 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t n;

	n = 0;
	if (!s)
		return (0);
	while (s[n])
		n++;
	return (n);
}
