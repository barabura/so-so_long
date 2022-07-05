/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:45 by baura             #+#    #+#             */
/*   Updated: 2022/07/04 18:57:06 by baura            ###   ########.fr       */
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

/* init image */
char	*open_image(char *path)
{
	if (open(path, O_RDONLY) < 0)
		error_message("Image opening error");
	return (path);
}

void	init_images(t_game *game)
{
	game->img_size = 100;
	game->empty_space_img = open_image("./imgs/background.xpm");
	game->wall_img = open_image("./imgs/wall.xpm");
	game->collectable_img = open_image("./imgs/coin_1.xpm");
	game->player_img = open_image("./imgs/cat_1.xpm");
	game->exit_img = open_image("./imgs/closed_box.xpm");
}



// int	animation(t_game *game)
// {
// 	int	i;
// 	i = 0;
// 	if (i < 1)
// 		put_img(game, "./imgs/coin_1.xpm", game->player_x * game->img_size, game->player_y * game->img_size);
// 	if (i > 1)
// 		put_img(game, "./imgs/coin_2.xpm", game->player_x * game->img_size, game->player_y * game->img_size);
// 	if (i > 2)
// 		put_img(game, "./imgs/coin.xpm", game->player_x * game->img_size, game->player_y * game->img_size);
// 	if (i > 3)
// 		put_img(game, "./imgs/coinxpm", game->player_x * game->img_size, game->player_y * game->img_size);
// 	if (i > 4)
// 		put_img(game, "./imgs/coin_5.xpm", game->player_x * game->img_size, game->player_y * game->img_size);
// 	if (i > 5)
// 		put_img(game, "./imgs/coin_6.xpm", game->player_x * game->img_size, game->player_y * game->img_size);
	
// 	i++;
// 	if (i > 6)
// 		i = 0;
// 	return (1);
// }

int	main(int argc, char **argv)
{
	t_game	game;
	int 	fd = 0;
	//int		i = 0;
		
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
	init_images(&game);
	make_window(&game);
	
	//while (game.map[i] != NULL)
	//{
	//	ft_putstr_fd("map:", 1);
	//	ft_putstr_fd(game.map[i], 1);
	//	ft_putchar_fd('\n', 1);
	//	i++;
	//}

	//while (game.map[0][game.width] != '\0')
	//	game.width += 1;
	//printf("%d", game.width);
	
	mlx_key_hook(game.mlx_win, key_hook, &game); // change 0
	mlx_hook(game.mlx_win, 17, 1L << 0, close_game, &game);
	mlx_loop(game.mlx);
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
