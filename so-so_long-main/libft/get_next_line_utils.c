/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:33:35 by baura             #+#    #+#             */
/*   Updated: 2022/04/14 17:32:19 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
	{
		while (s[i] != '\0')
			i++;
		return (&s[i]);
	}
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*gnl_strjoin(char *s, char *buf)
{
	size_t	i;
	size_t	j;
	char	*string;

	i = -1;
	j = 0;
	if (!s && !buf)
		return (NULL);
	if (!s)
	{
		s = (char *)malloc(sizeof(char) * 1);
		s[0] = '\0';
	}
	string = (char *)malloc(sizeof(char) * (gnl_strlen(s) + gnl_strlen(buf) + 1));
	if (string == NULL)
		return (NULL);
	while (s[++i] != '\0')
		string[i] = s[i];
	while (buf[j] != '\0')
		string[i++] = buf[j++];
	string[i] = '\0';
	free(s);
	return (string);
}
