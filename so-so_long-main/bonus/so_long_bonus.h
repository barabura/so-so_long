/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:23:13 by baura             #+#    #+#             */
/*   Updated: 2022/07/04 21:42:02 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# ifndef SCALE
# define SCALE 100
# endif
// # define SCALE 100
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	
	int		player;
	int		player_x;
	int		player_y;
	int		colletctible;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		steps;
	int		enemy;

	void	*mlx;
	void	*mlx_win;
	int		img_size;
	void	*img_ptr;

	void	*empty_space_img;
	void	*wall_img;
	void	*collectable_img;
	void	*exit_img;
	void	*open_exit_img;
	void	*player_img;
	void	*enemy_img;

}				t_game;

void	error_message(char *str);
void	convert_map_to_array(int fd, t_game *game);
void	check_map_params(t_game *game);
void	make_window(t_game *game);
void	put_img(t_game *game, void *path, int x, int y);
char	*open_image(char *path);

int	fill_window(t_game *game);
void	print_steps(t_game *game);

void	check_coins_near(t_game *game);

int		key_hook(int keycode, t_game *game);
int		close_game(t_game *game);

#endif
