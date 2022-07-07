/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:26:54 by baura             #+#    #+#             */
/*   Updated: 2022/07/07 16:27:57 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_check(t_game *game, int x, int y)
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
	if (game->map[y][x] == 'E' && game->exit == 0)
	{
		ft_putstr_fd("You won! Well done!\n", 1);
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(EXIT_SUCCESS);
	}
	if (game->map[y][x] == 'F')
	{
		ft_putstr_fd("You lose!\n", 1);
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(EXIT_FAILURE);
	}
	return (0);
}
