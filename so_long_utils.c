/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:41 by baura             #+#    #+#             */
/*   Updated: 2022/07/07 16:24:47 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *str)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

void	check_argument(int argc, char *arg)
{
	if (argc < 2)
		error_message("You must use a map to start the game");
	if (argc > 2)
		error_message("You can use only 1 map at a time");
	if (argc == 2)
	{
		if (ft_strnstr(arg, ".ber", 4) == 0)
			error_message("Your map must have .ber file extension");
	}
}

int	close_game(t_game *game)
{
	(void) game;
	ft_putstr_fd("Exit\n", 1);
	exit (EXIT_SUCCESS);
}

void	print_steps(t_game *game)
{
	char	*s;

	s = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->mlx_win, 10, 10, 0x000000, "Steps: ");
	mlx_string_put(game->mlx, game->mlx_win, 75, 10, 0x000000, s);
	free(s);
}
