/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:06:41 by baura             #+#    #+#             */
/*   Updated: 2022/07/06 15:33:16 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdbool.h>

int	close_game(t_game *game)
{
	(void) game;
	ft_putstr_fd("Exit\n", 1);
	exit (EXIT_SUCCESS);
}

//void	print_steps(t_game *game)
//{
//	char	*s;
//
//	s = ft_itoa(game->steps);
//	ft_putstr_fd("STEPS = ", 1);
//	ft_putstr_fd(s, 1);
//	ft_putchar_fd('\n', 1);
//	free(s);
//}

void	print_steps(t_game *game) // bonus
{
	char	*s;

	s = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->mlx_win, 10, 10, 0x000000, "Steps: ");
	mlx_string_put(game->mlx, game->mlx_win, 75, 10, 0x000000, s);
	free(s);
}

int    move_check(t_game *game, int x, int y) 
{
	if (game->map[y][x] == '0')
		return (1);
	if (game->map[y][x] == 'C')
	{
		game->colletctible -= 1;
		if (game->colletctible == 0)
			game->exit -= 1;
		return (1);
	}
	if (game->map[y][x] == 'E')
	{
        if (game->exit == 0)
        {
			ft_putstr_fd("You won! Well done!\n", 1);
			mlx_destroy_window(game->mlx, game->mlx_win);
			exit(EXIT_SUCCESS);
		}
        ft_putstr_fd("You need to collect all coins to open the box\n", 1);
	}
	if (game->map[y][x] == 'F')
	{
		ft_putstr_fd("You lose!\n", 1);
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(EXIT_FAILURE);
	}
	return (0);
}

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
		// print_steps(game);
		// printf("player: [%d][%d]\n", game->player_y, game->player_x);
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
		// print_steps(game);
        // printf("player: [%d][%d]\n", game->player_y, game->player_x);
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
		// print_steps(game);
        // printf("player: [%d][%d]\n", game->player_y, game->player_x);
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
		// print_steps(game);
        // printf("player: [%d][%d]\n", game->player_y, game->player_x);
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53) // ESC
    {
		ft_putstr_fd("Exit\n", 1);
        mlx_destroy_window(game->mlx, game->mlx_win);
		exit(EXIT_SUCCESS);
    }
	else if (keycode == 13 || keycode == 126) // W || ^
		move_up(game);
	else if (keycode == 0 || keycode == 123) // A || <
		move_left(game);
	else if (keycode == 1 || keycode == 125) // S || \/
		move_down(game);
	else if (keycode == 2 || keycode == 124) // D || >
		move_right(game);
	return (0);
}
