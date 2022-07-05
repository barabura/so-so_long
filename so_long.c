/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:45 by baura             #+#    #+#             */
/*   Updated: 2022/07/05 14:10:25 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *str)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
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
	game->img_size = 100;
}

void	check_argument(char *arg)
{
	if (ft_strnstr(arg, ".ber", 4) == 0)
		error_message("Your map must have .ber file extension");
}

void	init_images(t_game *game)
{
	game->empty_space_img = "./imgs/background.xpm";
	game->wall_img = "./imgs/wall.xpm";
	game->collectable_img = "./imgs/coin_1.xpm";
	game->player_img = "./imgs/cat_1.xpm";
	game->exit_img = "./imgs/closed_box.xpm";
}

t_game	*init(void)
{
	t_game	*game;
	
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		free(game);
		error_message("Map memory allocation error");
	}
	return (game);
}


int	main(int argc, char **argv)
{
	// t_game	game;
	t_game	*game;
	int 	fd = 0;
	//int		i = 0;
		
	if (argc < 2)
		error_message("You must use a map to start the game");
	if (argc > 2)
		error_message("Excessive number of arguments. You can use only 1 map at a time");
	if (argc == 2)
		check_argument(argv[1]);
	// init_game(&game);
	game = init();
	init_game(game);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_message("Map opening error");
	// convert_map_to_array(fd, &game);
	// check_map_params(&game);
	// init_images(&game);
	// make_window(&game);
	convert_map_to_array(fd, game);
	check_map_params(game);
	init_images(game);
	make_window(game);
	
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
	
	// mlx_key_hook(game.mlx_win, key_hook, &game); // change 0
	// mlx_hook(game.mlx_win, 17, 1L << 0, close_game, &game);
	// mlx_loop_hook(game.mlx, render_next_frame, &game);
	// mlx_loop(game.mlx);
	mlx_key_hook(game->mlx_win, key_hook, game); // change 0
	mlx_hook(game->mlx_win, 17, 1L << 0, close_game, game);
	// mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);
	return (0);
}
