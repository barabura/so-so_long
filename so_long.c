/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:45 by baura             #+#    #+#             */
/*   Updated: 2022/07/07 14:14:20 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void change_coin(t_game *game, int x, int y, int i)
{
	if (i > 10)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->empty_space_img, x * game->img_size, y * game->img_size);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->collectable2_img, x * game->img_size, y * game->img_size);
	}
	if (i > 20)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->empty_space_img, x * game->img_size, y * game->img_size);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->collectable3_img, x * game->img_size, y * game->img_size);
	}
	if (i > 30)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->empty_space_img, x * game->img_size, y * game->img_size);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->collectable4_img, x * game->img_size, y * game->img_size);
	}
	if (i > 40)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->empty_space_img, x * game->img_size, y * game->img_size);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->collectable5_img, x * game->img_size, y * game->img_size);
	}
	if (i > 50)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->empty_space_img, x * game->img_size, y * game->img_size);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->collectable6_img, x * game->img_size, y * game->img_size);
	}
	else if (i < 10)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->empty_space_img, x * game->img_size, y * game->img_size);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->collectable_img, x * game->img_size, y * game->img_size);
	}
}

void collectable_animation(t_game *game, int i)
{
	int	x;
	int	y;

	y = 0;
	while (++y < game->height)
	{
		x = 0;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'C')
				change_coin(game, x, y, i);
		}
	}
}

void	enemy_move(t_game *game, char *enemy)
{
	static int	next = 1;

	if (enemy[next] == 'P')
	{
		enemy[0] = '0';
		enemy[next] = 'F';
		ft_putstr_fd("You lose!\n", 1);
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(EXIT_FAILURE);
	}
	if (enemy[next] != '0')
	{
		next = -next;
	}
	if (enemy[next] == '0')
	{
		enemy[0] = '0';
		enemy[next] = 'F';
	}
}

void	enemy_animation(t_game *game, char **map)
{
	static int	n;
	int			i;

	while (*map && n == 30)
	{
		i = 0;
		while ((*map)[i])
		{
			if (map[0][i] == 'F')
			{
				enemy_move(game, &map[0][i]);
				i++;
			}
			i++;
		}
		map++;
	}
	if (++n > 60)
		n = 0;
}

int get_animation(t_game *game)
{
	static int	i;

	collectable_animation(game, i);
	enemy_animation(game, game->map);
	i++;
	if (i > 60)
		i = 0;
	return (0);
}



int	main(int argc, char **argv)
{
	t_game	*game;
	int		fd = 0;

	check_argument(argc, argv[1]);
	game = init();
	init_game(game);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_message("Map opening error");
	convert_map_to_array(fd, game);
	check_map_params(game);
	make_window(game);
	init_images(game);
	mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_hook(game->mlx_win, 17, 1L << 0, close_game, game);
	mlx_loop_hook(game->mlx, fill_window, game);
	mlx_loop(game->mlx);
	return (0);
}
