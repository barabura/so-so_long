/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:47:40 by baura             #+#    #+#             */
/*   Updated: 2022/07/07 17:05:16 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_coin_2(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->empty_space_img, x * game->img_size, y * game->img_size);
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->collectable2_img, x * game->img_size, y * game->img_size);
}

void	put_coin_3(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->empty_space_img, x * game->img_size, y * game->img_size);
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->collectable3_img, x * game->img_size, y * game->img_size);
}

void	put_coin_4(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->empty_space_img, x * game->img_size, y * game->img_size);
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->collectable4_img, x * game->img_size, y * game->img_size);
}

void	put_coin_5(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->empty_space_img, x * game->img_size, y * game->img_size);
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->collectable5_img, x * game->img_size, y * game->img_size);
}

void	change_coin(t_game *game, int x, int y, int i)
{
	if (i > 10)
		put_coin_2(game, x, y);
	if (i > 20)
		put_coin_3(game, x, y);
	if (i > 30)
		put_coin_4(game, x, y);
	if (i > 40)
		put_coin_5(game, x, y);
	if (i > 50)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->empty_space_img, x * game->img_size, y * game->img_size);
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->collectable6_img, x * game->img_size, y * game->img_size);
	}
	else if (i < 10)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->empty_space_img, x * game->img_size, y * game->img_size);
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->collectable_img, x * game->img_size, y * game->img_size);
	}
}
