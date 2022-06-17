/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:06:25 by baura             #+#    #+#             */
/*   Updated: 2021/10/28 17:09:02 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d;

	i = 0;
	d = ft_strlen(dst);
	if (d >= dstsize)
		return (dstsize + ft_strlen(src));
	if (d < (dstsize - 1) && dstsize > 0)
	{
		while (src[i] != '\0' && (d + i) < (dstsize - 1))
		{
			dst[d + i] = src[i];
			i++;
		}
		dst[d + i] = '\0';
	}
	return (d + ft_strlen(src));
}
