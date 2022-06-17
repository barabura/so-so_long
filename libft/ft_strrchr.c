/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:14:04 by baura             #+#    #+#             */
/*   Updated: 2021/10/28 17:11:24 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(str);
	if (c == '\0')
		return (&str[i]);
	while (i > 0 && s[i] != c)
		i--;
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}
