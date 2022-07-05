/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:06:41 by baura             #+#    #+#             */
/*   Updated: 2022/07/04 22:33:09 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	(void) game;
	// mlx_destroy_window(game->mlx, game->mlx_win);
	exit (EXIT_SUCCESS);
}

void	print_steps(t_game *game)
{
	char	*s;

	s = ft_itoa(game->steps);
	ft_putstr_fd("STEPS = ", 1);
	ft_putstr_fd(s, 1);
	ft_putchar_fd('\n', 1);
	free(s);
}

void	check_collectibles(t_game *game)
{
	if (game->colletctible == 0)
	{
		// put_img(game, game->empty_space_img, game->exit_x * game->img_size, game->exit_y * game->img_size);
		// put_img(game, game->open_exit_img, game->exit_x * game->img_size, game->exit_y * game->img_size);
		game->exit -= 1;
	}
}

int    move_check(t_game *game, int x, int y) 
{
	if (game->map[y][x] == '0')
	{
		put_img(game, game->player_img, x * game->img_size, y * game->img_size);
		put_img(game, game->empty_space_img, game->player_x * game->img_size, \
				game->player_y * game->img_size);
		return (1);
	}
	if (game->map[y][x] == 'C')
	{
		put_img(game, game->player_img, x * game->img_size, y * game->img_size);
		put_img(game, game->empty_space_img, game->player_x * game->img_size, \
				game->player_y * game->img_size);
		game->colletctible -= 1;
		check_collectibles(game);
		return (1);
	}
	if (game->map[y][x] == 'E') // check
	{
        if (game->exit == 0)
        {
			put_img(game, game->empty_space_img, game->player_x * game->img_size, \
            		game->player_y * game->img_size);
			ft_putstr_fd("You won! Well done!\n", 1);
			mlx_destroy_window(game->mlx, game->mlx_win);
			exit(EXIT_SUCCESS);
		}
        ft_putstr_fd("You need to collect all coins to open the box\n", 1);
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
		print_steps(game);
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
		print_steps(game);
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
		print_steps(game);
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
		print_steps(game);
        // printf("player: [%d][%d]\n", game->player_y, game->player_x);
	}
}

int	key_hook(int keycode, t_game *game)
{
	// printf("%d\n", keycode);
	if (keycode == 13) // W
		move_up(game);
	else if (keycode == 0) // A
		move_left(game);
	else if (keycode == 1) // S
		move_down(game);
	else if (keycode == 2) // D
		move_right(game);
	else if (keycode == 53) // ESC
    {
        mlx_destroy_window(game->mlx, game->mlx_win);
		exit(EXIT_SUCCESS);
    }
	return (0);
}
