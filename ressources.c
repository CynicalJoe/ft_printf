/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ressources.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:38:18 by gtournay          #+#    #+#             */
/*   Updated: 2020/10/08 09:38:22 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*copy_conv(char *src, char *dest, size_t index, size_t start)
{
	size_t j;

	j = index;
	while (src[start])
	{
		dest[j] = src[start];
		start++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*copy_start(char *src, char *dest, size_t index)
{
	size_t	i;

	i = 0;
	while (i != index)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*hex_conv(unsigned long int n, char *base)
{
	unsigned long int		r;
	size_t					i;
	char					*ret;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * 9)))
		return (NULL);
	while (i < 8)
	{
		ret[i] = '.';
		i++;
	}
	ret[8] = '\0';
	i--;
	if (n == 0)
		ret[7] = '0';
	while (n)
	{
		r = n % 16;
		n = n / 16;
		ret[i] = base[r];
		i--;
	}
	return (ret);
}

char	*hex_clean(char *hexa)
{
	char	*ret;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(hexa);
	while (hexa[i] == '.')
		i++;
	if (!(ret = malloc(sizeof(char) * (len - i + 1))))
		return (NULL);
	len = 0;
	while (hexa[i])
	{
		ret[len] = hexa[i];
		i++;
		len++;
	}
	ret[len] = '\0';
	free(hexa);
	return (ret);
}

char	*adr_frmt(char *hexa)
{
	char	*adr;
	size_t	i;
	size_t	len;

	i = 0;
	while (hexa[i] == '.')
		i++;
	len = ft_strlen(hexa) - i + 3;
	if (!(adr = malloc(sizeof(char) * len)))
		return (NULL);
	adr[0] = '0';
	adr[1] = 'x';
	len = 2;
	while (hexa[i])
	{
		adr[len] = hexa[i];
		len++;
		i++;
	}
	adr[len] = '\0';
	free(hexa);
	return (adr);
}
