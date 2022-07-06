/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:17:06 by baura             #+#    #+#             */
/*   Updated: 2022/07/06 14:39:55 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* fill window */
void	put_img(t_game *game, void *path, int x, int y)
{
	open_image(path);
	game->img_ptr = mlx_xpm_file_to_image(game->mlx, path, &game->img_size, &game->img_size);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_ptr, x, y);
}

void	check_coins_near(t_game *game)
{
	if ((game->map[game->player_y][game->player_x + 1] == 'C') ||
		(game->map[game->player_y][game->player_x - 1] == 'C') ||
		(game->map[game->player_y + 1][game->player_x] == 'C') ||
		(game->map[game->player_y - 1][game->player_x] == 'C'))
			put_img(game, "./imgs/cat_2.xpm", game->player_x * SCALE, game->player_y * SCALE);
}

int	fill_window(t_game *game)
{
	int	w;
	int	h;
	
	h = 0;
	while (h < game->height)
	{
		w = 0;
		while (game->map[h][w])
		{
			if (game->map[h][w] == '1')
				put_img(game, game->wall_img, w * SCALE, h * SCALE);
			if (game->map[h][w] == '0')
				put_img(game, game->empty_space_img, w * SCALE, h * SCALE);
			if (game->map[h][w] == 'C')
			{
				put_img(game, game->empty_space_img, w * SCALE, h * SCALE);
				put_img(game, game->collectable_img, w * SCALE, h * SCALE);
			}
			if (game->map[h][w] == 'P')
			{
				put_img(game, game->player_img, w * SCALE, h * SCALE);
				game->player_x = w;
				game->player_y = h;
				check_coins_near(game);
			}
			if (game->map[h][w] == 'E')
			{
				put_img(game, game->empty_space_img, w * SCALE, h * SCALE);
				if (game->colletctible == 0)
					put_img(game, game->open_exit_img, w * SCALE, h * SCALE);
				else
					put_img(game, game->exit_img, w * SCALE, h * SCALE);
				game->exit_x = w;
				game->exit_y = h;
			}
			if (game->map[h][w] == 'F')
			{
				put_img(game, game->empty_space_img, w * SCALE, h * SCALE);
				put_img(game, game->enemy_img, w * SCALE, h * SCALE);
			}
			w++;
		}
		h++;
	}
	return (1);
}

void	make_window(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->width * SCALE, game->height * SCALE, "so_long");
	fill_window(game);
}
