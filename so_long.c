/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:45 by baura             #+#    #+#             */
/*   Updated: 2022/07/07 17:06:18 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		fd;

	check_argument(argc, argv[1]);
	game = init();
	init_game(game);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_message("Map opening error");
	convert_map_to_array(fd, game);
	check_map_params(game);
	make_window(game);
	init_images(game);
	mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_hook(game->mlx_win, 17, 1L << 0, close_game, game);
	mlx_loop_hook(game->mlx, fill_window, game);
	mlx_loop(game->mlx);
	return (0);
}
