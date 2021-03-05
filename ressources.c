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

char	*hex_conv(unsigned long long int n, char *base)
{
	unsigned long long int		r;
	size_t						i;
	char						*ret;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	while (i < 20)
	{
		ret[i] = '.';
		i++;
	}
	ret[20] = '\0';
	i--;
	if (n == 0)
		ret[19] = '0';
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
	if (!hexa)
		return (NULL);
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
	if (!hexa)
		return (NULL);
	while (hexa[i] == '.')
		i++;
	len = ft_strlen(hexa) - i + 3;
	if (!(adr = malloc(sizeof(char) * len)))
		return (NULL);
	adr[0] = '0';
	adr[1] = 'x';
	len = 2;
	while (hexa[i])
		adr[len++] = hexa[i++];
	adr[len] = '\0';
	free(hexa);
	return (adr);
}
