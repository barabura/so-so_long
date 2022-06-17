/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:01:25 by baura             #+#    #+#             */
/*   Updated: 2021/10/28 17:06:43 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	count;
	char	*s2;

	i = 0;
	count = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (count + 1));
	if (s2 == NULL)
		return (NULL);
	while (count--)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
