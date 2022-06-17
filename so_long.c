/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:45 by baura             #+#    #+#             */
/*   Updated: 2022/06/17 17:08:03 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *str)
{
	ft_putstr_fd("Error: ", STDERR_FILENO); //STDERR_FILENO
	ft_putstr_fd(str, STDERR_FILENO);
	write(1, "\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	init_game(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->player = 0;
	game->colletctible = 0;
	game->exit = 0;
	game->steps = 0;
}

void	check_argument(char *arg)
{
	if (ft_strnstr(arg, ".ber", 4) == 0)
		error_message("Your map must have .ber file extension");
}

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
		error_message("Wrong fd or buf size"); // ????????
	ret = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (buf == NULL)
		error_message("Memory allocation error"); // error for mem alloc
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
	//printf("saved:\n%s\n", saved_str);
	game->map = ft_split(saved_str, '\n');
	free(saved_str);
	close(fd);
}


void	check_symbols_amount(t_game *game)
{
	int	w;
	
	w = 0;
	
	while (game->map[game->height - 1][w])
	{
		if (game->map[game->height - 1][w] != '1')
			error_message("There're no walls at the bottom line");
		w++;
	}
	if (game->player < 1)
		error_message("Add player to start the game");
	if (game->colletctible < 1)
		error_message("Add at least 1 collectible to start the game");
	if (game->exit < 1)
		error_message("You need exit to finish the game");
}

void	check_map_symbols(t_game *game)
{
	int	width;

	width = 0;
	while (game->map[game->height][++width])
	{
		if ((game->map[game->height][width] != '0') &&
			(game->map[game->height][width] != '1') &&
			(game->map[game->height][width] != 'C') &&
			(game->map[game->height][width] != 'E') &&
			(game->map[game->height][width] != 'P'))
			error_message("Invalid symbols on the map");
		if (game->map[game->height][width] == 'P')
			game->player++;
		//printf("player: %d\n", game->player); // comment it
		if (game->player > 1)
			error_message("There must be one player");
		if (game->map[game->height][width] == 'C')
			game->colletctible++;
		//printf("collectible: %d\n", game->colletctible); // comment it
		if (game->map[game->height][width] == 'E')
			game->exit++;
		//printf("exit: %d\n", game->exit); // comment it
		if (game->exit > 1)
			error_message("There must be one exit");
	}
}

void	check_map_params(t_game *game) // ADD check last string for 1111111 - DONE
{
	while (game->map[0][game->width])
	{
		if (game->map[0][game->width] != '1')
			error_message("There're no walls at the top line");
		game->width += 1;
	}
	//printf("width: %d\n", game->width);
	if (game->width > 51) // check this number
		error_message("The map is too wide");
	while (game->map[game->height])
	{
		if ((ft_strlen(game->map[game->height])) != (size_t)game->width)
			error_message("Map's not rectangle");
		if ((game->map[game->height][0] != '1') ||
			(game->map[game->height][game->width - 1] != '1'))
			error_message("There're no walls on the sides");
		check_map_symbols(game);
		game->height += 1;
		if (game->height > 28) // and this one check
			error_message("Map's too high");
	}
	//printf("height: %d\n", game->height);
	check_symbols_amount(game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int 	fd = 0;
	int		i = 0;
		
	if (argc < 2)
		error_message("You must use a map to start the game");
	if (argc > 2)
		error_message("Excessive number of arguments. You can use only 1 map at a time");
	if (argc == 2)
		check_argument(argv[1]);

	init_game(&game);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_message("Map opening error");
	convert_map_to_array(fd, &game);
	check_map_params(&game);
	
	
	while (game.map[i] != NULL)
	{
		ft_putstr_fd("map:", 1);
		ft_putstr_fd(game.map[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}

	//while (game.map[0][game.width] != '\0')
	//	game.width += 1;
	//printf("%d", game.width);
	
	return (0);
}


//int	main(void)
//{
//	char	*line;
//	int		i;
//	int		fd1;
//	/*int		fd1;
//	int		fd2;
//	int		fd3;*/
//	//fd = 0;
//	fd1 = open("map.ber", O_RDONLY);
//	/*fd2 = open("tests/file2.txt", O_RDONLY);
//	fd3 = open("tests/file3.txt", O_RDONLY)*/
//	i = 1;
//	while (i < 7)
//	{
//		line = get_next_line(fd1);
//		ft_putstr_fd(line, 1);
//		//printf("line [%02d]: %s", i, line);
//		free(line);
//		/*line = get_next_line(fd1);
//		printf("line [%02d]: %s", i, line);
//		free(line);
//		line = get_next_line(fd2);
//		printf("line [%02d]: %s", i, line);
//		free(line);
//		line = get_next_line(fd3);
//		printf("line [%02d]: %s", i, line);
//		free(line);*/
//		i++;
//	}
//	close(fd1);
//	/*close(fd2);
//	close(fd3);*/
//	return (0);
//}
