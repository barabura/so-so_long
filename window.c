/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:17:06 by baura             #+#    #+#             */
/*   Updated: 2022/07/05 19:25:45 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_game *game, void *path, int x, int y)
{
	game->img_ptr = mlx_xpm_file_to_image(game->mlx, path, &game->img_size, &game->img_size);
	if (game->img_ptr == NULL)
		error_message("Image opening error");
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_ptr, x, y);
}

void	check_coins_near(t_game *game) // bonus
{
	if ((game->map[game->player_y][game->player_x + 1] == 'C') ||
		(game->map[game->player_y][game->player_x - 1] == 'C') ||
		(game->map[game->player_y + 1][game->player_x] == 'C') ||
		(game->map[game->player_y - 1][game->player_x] == 'C'))
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->player2_img, game->player_x * game->img_size, game->player_y * game->img_size);
}

void	fill_window(t_game *game)
{
	int	w;
	int	h;
	
	h = -1;
	while (++h < game->height)
	{
		w = -1;
		while (game->map[h][++w])
		{
			if (game->map[h][w] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall_img, w * game->img_size, h * game->img_size); /// *********************
			if (game->map[h][w] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->empty_space_img, w * game->img_size, h * game->img_size);
			if (game->map[h][w] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->empty_space_img, w * game->img_size, h * game->img_size);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->collectable_img, w * game->img_size, h * game->img_size);
			}
			if (game->map[h][w] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->player_img, w * game->img_size, h * game->img_size);
				game->player_x = w;
				game->player_y = h;
				check_coins_near(game); // bonus
			}
			if (game->map[h][w] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->empty_space_img, w * game->img_size, h * game->img_size);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit_img, w * game->img_size, h * game->img_size);
				game->exit_x = w;
				game->exit_y = h;
			}
		}
	}
}

void	make_window(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->width * game->img_size, \
					game->height * game->img_size, "so_long");
	// fill_window(game);
}
