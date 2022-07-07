/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:06:41 by baura             #+#    #+#             */
/*   Updated: 2022/07/07 16:32:09 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y - 1;
	if (move_check(game, x, y))
	{
		game->map[game->player_y][x] = '0';
		game->map[y][x] = 'P';
		game->player_y = y;
		game->steps++;
	}
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x - 1;
	y = game->player_y;
	if (move_check(game, x, y))
	{
		game->map[y][game->player_x] = '0';
		game->map[y][x] = 'P';
		game->player_x = x;
		game->steps++;
	}
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y + 1;
	if (move_check(game, x, y))
	{
		game->map[game->player_y][x] = '0';
		game->map[y][x] = 'P';
		game->player_y = y;
		game->steps++;
	}
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x + 1;
	y = game->player_y;
	if (move_check(game, x, y))
	{
		game->map[y][game->player_x] = '0';
		game->map[y][x] = 'P';
		game->player_x = x;
		game->steps++;
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		ft_putstr_fd("Exit\n", 1);
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 13 || keycode == 126)
		move_up(game);
	else if (keycode == 0 || keycode == 123)
		move_left(game);
	else if (keycode == 1 || keycode == 125)
		move_down(game);
	else if (keycode == 2 || keycode == 124)
		move_right(game);
	return (0);
}
