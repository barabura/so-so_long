/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:11:13 by baura             #+#    #+#             */
/*   Updated: 2022/04/14 17:47:32 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h;
	char	*n;

	i = 0;
	h = (char *)haystack;
	n = (char *)needle;
	if (n[0] == '\0')
		return (h);
	while (h[i] != '\0')
	{
		j = 0;
		while (h[i + j] == n[j] && j < len)
		{
			if (h[i + j] == '\0' && n[j] == '\0' )
				return (&h[i]);
			j++;
		}
		if (n[j] == '\0')
			return (h + i);
		i++;
	}
	return (NULL);
}
