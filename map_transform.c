/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:12:25 by baura             #+#    #+#             */
/*   Updated: 2022/07/07 16:12:34 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*sl_strjoin(char *s, char *buf)
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
	string = (char *)malloc(sizeof(char) * (ft_strlen(s) + ft_strlen(buf) + 1));
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

void	convert_map_to_array(int fd, t_game *game)
{
	int		ret;
	char	*buf;
	char	*saved_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		error_message("Wrong fd or buf size");
	ret = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (buf == NULL)
		error_message("Memory allocation error");
	while (ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			error_message("Map reading error");
		}
		buf[ret] = '\0';
		saved_str = sl_strjoin(saved_str, buf);
	}
	free(buf);
	game->map = ft_split(saved_str, '\n');
	free(saved_str);
	close(fd);
}
