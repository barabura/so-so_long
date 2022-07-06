/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:48 by baura             #+#    #+#             */
/*   Updated: 2022/07/06 15:23:25 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "libft/libft.h"
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
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
	int		enemy;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		steps;

	void	*mlx;
	void	*mlx_win;
	
	int		img_size;
	int		img_w;
	int		img_h;

	void	*empty_space_img;
	void	*wall_img;
	void	*collectable_img;
	void	*collectable2_img;
	void	*collectable3_img;
	void	*collectable4_img;
	void	*collectable5_img;
	void	*collectable6_img;
	void	*enemy_r_img;
	void	*enemy_l_img;
	void	*exit_img;
	void	*exit2_img;
	void	*player_img;
	void	*player2_img;

}				t_game;

void	error_message(char *str);
void	convert_map_to_array(int fd, t_game *game);
void	check_map_params(t_game *game);
void	make_window(t_game *game);
void	put_img(t_game *game, void *path, int x, int y);

int		key_hook(int keycode, t_game *game);
int		close_game(t_game *game);

void	check_coins_near(t_game *game);
int		fill_window(t_game *game);
void	print_steps(t_game *game);
int 	get_animation(t_game *game);

#endif
