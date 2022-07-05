/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:33:28 by baura             #+#    #+#             */
/*   Updated: 2022/04/11 18:04:02 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save_str(char *saved_strs)
{
	int		i;
	char	*str;

	i = 0;
	if (!saved_strs[i])
		return (NULL);
	while (saved_strs[i] != '\n' && saved_strs[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (saved_strs[i] != '\n' && saved_strs[i] != '\0')
	{
		str[i] = saved_strs[i];
		i++;
	}
	if (saved_strs[i] == '\n')
	{
		str[i] = saved_strs[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_change_str(char *saved_strs)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (saved_strs[i] != '\n' && saved_strs[i] != '\0')
		i++;
	if (!saved_strs[i])
	{
		free(saved_strs);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (gnl_strlen(saved_strs) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (saved_strs[i])
		str[j++] = saved_strs[i++];
	str[j] = '\0';
	free(saved_strs);
	return (str);
}

char	*ft_read_line(int fd, char *saved_strs)
{
	int		ret;
	char	*buf;

	ret = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (!gnl_strchr(saved_strs, '\n') && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[ret] = '\0';
		saved_strs = gnl_strjoin(saved_strs, buf);
	}
	free (buf);
	return (saved_strs);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*saved_strs;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved_strs = ft_read_line(fd, saved_strs);
	if (!saved_strs)
		return (NULL);
	str = ft_save_str(saved_strs);
	saved_strs = ft_change_str(saved_strs);
	return (str);
}
