/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:56:58 by baura             #+#    #+#             */
/*   Updated: 2022/07/04 20:42:39 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_symbols_amount(t_game *game)
{
	int	w;
	
	w = 0;
	
	while (game->map[game->height - 1][w])
	{
		if (game->map[game->height - 1][w] != '1')
			error_message("There're no walls at the bottom line");
		w++;
	}
	if (game->player < 1)
		error_message("Add player to start the game");
	if (game->enemy < 1)
		error_message("Add enemy to fight for coins");
	if (game->colletctible < 1)
		error_message("Add at least 1 collectible to start the game");
	if (game->exit < 1)
		error_message("You need exit to finish the game");
}

void	check_map_symbols(t_game *game)
{
	int	width;

	width = 0;
	while (game->map[game->height][++width])
	{
		if ((game->map[game->height][width] != '0') &&
			(game->map[game->height][width] != '1') &&
			(game->map[game->height][width] != 'C') &&
			(game->map[game->height][width] != 'E') &&
			(game->map[game->height][width] != 'P') &&
			(game->map[game->height][width] != 'F'))
			error_message("Invalid symbols on the map");
		if (game->map[game->height][width] == 'P')
			game->player++;
		//printf("player: %d\n", game->player); // comment it
		if (game->player > 1)
			error_message("There must be one player");
		if (game->map[game->height][width] == 'F')
			game->enemy++;
		if (game->map[game->height][width] == 'C')
			game->colletctible++;
		//printf("collectible: %d\n", game->colletctible); // comment it
		if (game->map[game->height][width] == 'E')
			game->exit++;
		//printf("exit: %d\n", game->exit); // comment it
		if (game->exit > 1)
			error_message("There must be one exit");
	}
}

void	check_map_params(t_game *game)
{
	while (game->map[0][game->width])
	{
		if (game->map[0][game->width] != '1')
			error_message("There're no walls at the top line");
		game->width += 1;
	}
	// printf("width: %d\n", game->width);
	if (game->width > 51) // check this number
		error_message("The map is too wide");
	while (game->map[game->height])
	{
		if ((ft_strlen(game->map[game->height])) != (size_t)game->width)
			error_message("Map's not rectangle");
		if ((game->map[game->height][0] != '1') ||
			(game->map[game->height][game->width - 1] != '1'))
			error_message("There're no walls on the sides");
		check_map_symbols(game);
		game->height += 1;
		if (game->height > 28) // and this one check
			error_message("Map's too high");
	}
	// printf("height: %d\n", game->height);
	check_symbols_amount(game);
}
