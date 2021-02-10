/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:38:18 by gtournay          #+#    #+#             */
/*   Updated: 2020/10/08 09:38:22 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_size(unsigned int n)
{
	size_t	size;

	size = 1;
	while (n / 10 > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_untoa(unsigned int n)
{
	size_t	size;
	char	*res;

	size = 1;
	size = get_size(n);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res[size] = '\0';
	while (size)
	{
		res[size - 1] = n % 10 + '0';
		n /= 10;
		size--;
	}
	return (res);
}
