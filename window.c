/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:17:06 by baura             #+#    #+#             */
/*   Updated: 2022/07/07 16:16:19 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_coins_near(t_game *game)
{
	if ((game->map[game->player_y][game->player_x + 1] == 'C') ||
		(game->map[game->player_y][game->player_x - 1] == 'C') ||
		(game->map[game->player_y + 1][game->player_x] == 'C') ||
		(game->map[game->player_y - 1][game->player_x] == 'C'))
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->player2_img, \
		game->player_x * game->img_size, game->player_y * game->img_size);
}

void	put_player_img(t_game *game, int w, int h)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->player_img, w * game->img_size, h * game->img_size);
	game->player_x = w;
	game->player_y = h;
	check_coins_near(game);
}

void	put_exit_img(t_game *game, int w, int h)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->empty_space_img, w * game->img_size, h * game->img_size);
	if (game->colletctible == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->exit2_img, w * game->img_size, h * game->img_size);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->exit_img, w * game->img_size, h * game->img_size);
	game->exit_x = w;
	game->exit_y = h;
}

void	put_images(t_game *game, int w, int h)
{
	if (game->map[h][w] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->wall_img, w * game->img_size, h * game->img_size);
	if (game->map[h][w] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->empty_space_img, w * game->img_size, h * game->img_size);
	if (game->map[h][w] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->empty_space_img, w * game->img_size, h * game->img_size);
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->collectable_img, w * game->img_size, h * game->img_size);
	}
	if (game->map[h][w] == 'F')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->empty_space_img, w * game->img_size, h * game->img_size);
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->enemy_img, w * game->img_size, h * game->img_size);
	}
	if (game->map[h][w] == 'P')
		put_player_img(game, w, h);
	if (game->map[h][w] == 'E')
		put_exit_img(game, w, h);
}

int	fill_window(t_game *game)
{
	int	w;
	int	h;
	
	h = -1;
	while (++h < game->height)
	{
		w = -1;
		while (game->map[h][++w])
			put_images(game, w, h);
	}
	get_animation(game);
	print_steps(game);
	return (1);
}

void	make_window(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->width * game->img_size, \
					game->height * game->img_size, "so_long");
}
