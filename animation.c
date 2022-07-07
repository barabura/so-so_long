/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:41:36 by baura             #+#    #+#             */
/*   Updated: 2022/07/07 17:01:36 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectable_animation(t_game *game, int i)
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

int	get_animation(t_game *game)
{
	static int	i;

	collectable_animation(game, i);
	enemy_animation(game, game->map);
	i++;
	if (i > 60)
		i = 0;
	return (0);
}
