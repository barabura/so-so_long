/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:45 by baura             #+#    #+#             */
/*   Updated: 2022/07/04 22:37:57 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_message(char *str)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
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
	game->enemy = 0;
	game->img_size = 100;
}

void	check_argument(char *arg)
{
	if (ft_strnstr(arg, ".ber", 4) == 0)
		error_message("Your map must have .ber file extension");
}


char	*open_image(char *path)
{
	if (open(path, O_RDONLY) < 0)
		error_message("Image opening error");
	return (path);
}

void	init_images(t_game *game)
{
	game->empty_space_img = open_image("./imgs/background.xpm");
	game->wall_img = open_image("./imgs/wall.xpm");
	game->collectable_img = open_image("./imgs/coin_1.xpm");
	game->player_img = open_image("./imgs/cat_1.xpm");
	game->enemy_img = open_image("./imgs/cleaner.xpm");
	game->exit_img = open_image("./imgs/closed_box.xpm");
	game->open_exit_img = open_image("./imgs/open_box.xpm");
}




int	main(int argc, char **argv)
{
	t_game	game;
	int 	fd = 0;
		
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
	mlx_key_hook(game.mlx_win, key_hook, &game); // change 0
	mlx_hook(game.mlx_win, 17, 1L << 0, close_game, &game);
	// mlx_loop_hook(game.mlx, check_coins_near, &game);
	mlx_loop(game.mlx);
	return (0);
}
