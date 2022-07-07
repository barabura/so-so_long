/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:41 by baura             #+#    #+#             */
/*   Updated: 2022/07/07 14:30:38 by baura            ###   ########.fr       */
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
		error_message("Excessive number of arguments. You can use only 1 map at a time");
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
