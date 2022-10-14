/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:08:51 by adubeau           #+#    #+#             */
/*   Updated: 2021/06/20 15:43:54 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "log.h"

int	ft_len(int nb)
{
	int	i;

	i = 0;
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	if (nb < 0)
		i++;
	return (i + 1);
}

char	*ft_make_itoa(char *str, int n, int len)
{
	int	i;

	i = len - 1;
	while (n >= 10)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	str[i] = n % 10 + '0';
	str[len] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		nb;
	char	*str;
	int		len;

	nb = n;
	if (n == -2147483648)
	{
		return (str = strdup("-2147483648"));
	}
	if (n < 0)
		nb = -n;
	len = ft_len(nb);
	if (n < 0)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	ft_make_itoa(str, nb, len);
	return (str);
}