/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:47:49 by baura             #+#    #+#             */
/*   Updated: 2021/10/28 16:56:40 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_symbol_counter(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_zero(char *str)
{
	str = (char *)malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long int	nb;

	str = NULL;
	if (n == 0)
		return (ft_zero(str));
	len = ft_symbol_counter(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	nb = n;
	if (nb < 0)
		nb = -nb;
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[len] = '-';
	return (str);
}
