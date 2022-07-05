/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:45 by baura             #+#    #+#             */
/*   Updated: 2022/07/05 19:35:48 by baura            ###   ########.fr       */
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
	game->empty_space_img = mlx_xpm_file_to_image(game->mlx, "./imgs/background.xpm", &game->img_size, &game->img_size);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "./imgs/wall.xpm", &game->img_size, &game->img_size);
	game->collectable_img = mlx_xpm_file_to_image(game->mlx, "./imgs/coin_1.xpm", &game->img_size, &game->img_size);
	game->collectable2_img = mlx_xpm_file_to_image(game->mlx, "./imgs/coin_2.xpm", &game->img_size, &game->img_size);
	game->collectable3_img = mlx_xpm_file_to_image(game->mlx, "./imgs/coin_3.xpm", &game->img_size, &game->img_size);
	game->collectable4_img = mlx_xpm_file_to_image(game->mlx, "./imgs/coin_4.xpm", &game->img_size, &game->img_size);
	game->collectable5_img = mlx_xpm_file_to_image(game->mlx, "./imgs/coin_5.xpm", &game->img_size, &game->img_size);
	game->collectable6_img = mlx_xpm_file_to_image(game->mlx, "./imgs/coin_6.xpm", &game->img_size, &game->img_size);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "./imgs/cat_1.xpm", &game->img_size, &game->img_size);
	game->player2_img = mlx_xpm_file_to_image(game->mlx, "./imgs/cat_2.xpm", &game->img_size, &game->img_size);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "./imgs/closed_box.xpm", &game->img_size, &game->img_size);	
	// game->exit2_img = mlx_xpm_file_to_image(game->mlx, "./imgs/open_box.xpm", &game->img_size, &game->img_size);
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




// void change_coin(t_game *game, int x, int y, int i)
// {
// 	if (i > 10)
// 	{
// 		// game->collectable_img = 
// 		put_img(game, game->empty_space_img, x, y);
// 		put_img(game, "./imgs/coin_2.xpm", x, y);
// 	}
// 	if (i > 20)
// 	{
// 		put_img(game, game->empty_space_img, x, y);
// 		put_img(game, "./imgs/coin_3.xpm", x, y);
// 	}
// 	if (i > 30)
// 	{
// 		put_img(game, game->empty_space_img, x, y);
// 		put_img(game, "./imgs/coin_4.xpm", x, y);
// 	}
// 	if (i > 40)
// 	{
// 		put_img(game, game->empty_space_img, x, y);
// 		put_img(game, "./imgs/coin_5.xpm", x, y);
// 	}
// 	if (i > 50)
// 	{
// 		put_img(game, game->empty_space_img, x, y);
// 		put_img(game, "./imgs/coin_6.xpm", x, y);
// 	}
// 	else if (i < 10)
// 	{
// 		put_img(game, game->empty_space_img, x, y);
// 		put_img(game, "./imgs/coin_1.xpm", x, y);
// 	}
// }

// void collectable_animation(t_game *game, int i)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (++y < game->height)
// 	{
// 		x = 0;
// 		while (game->map[y][++x])
// 		{
// 			if (game->map[y][x] == 'C')
// 			{
// 				printf("%c", game->map[y][x]);	
// 				change_coin(game, x, y, i);
// 			}
// 		}
// 	}
// }

// int get_animation(t_game *game)
// {
// 	static int	i;

// 	collectable_animation(game, i);
// 	i++;
// 	if (i > 60)
// 		i = 0;
// 	return (0);
// }



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
	make_window(game);
	init_images(game);
	fill_window(game);
	
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
	// mlx_loop(game.mlx);
	mlx_key_hook(game->mlx_win, key_hook, game); // change 0
	mlx_hook(game->mlx_win, 17, 1L << 0, close_game, game);
	// mlx_loop_hook(game->mlx, get_animation, game);
	mlx_loop(game->mlx);
	return (0);
}
