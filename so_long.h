/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:48 by baura             #+#    #+#             */
/*   Updated: 2022/06/20 22:14:23 by baura            ###   ########.fr       */
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



///* MLX WINDOW STRUCTURE */
//typedef struct s_mlx
//{
//	void	*mlx;
//	void	*mlx_win;
//}				t_mlx;

///* IMAGE */
//typedef struct s_img
//{
//	void	*img;
//	int		width;
//	int		height;
//}				t_img;
///* PLAYER */
//typedef struct s_player
//{
//	t_img	*player;
//	int		x;
//	int		y;
//	int		steps;
//	int		collect;
//	int		exit_done;
//}				t_player;
///* MAP */
//typedef struct s_map
//{
//	char	**map;
//	int		width;
//	int		height;
//	int		empty_space;
//	int		wall;
//	int		collectible;
//	int		exit;
//	int		player;
//	int		enemy;
//}				t_map;
///* GAME ATRIBUTES */
//typedef struct s_game
//{
//	t_map		*map;
//	t_mlx		*mlx;
//	t_player	*player;
//	t_img		*background;
//	t_img		*wall;
//	t_img		*collectable;
//	t_img		*exit_0;
//	t_img		*enemy;
//}				t_game;

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

	void	*mlx;
	void	*mlx_win;
	int		img_size;
	void	*img_ptr;

	void	*empty_space_img;
	void	*wall_img;
	void	*collectable_img;
	void	*exit_img;
	void	*player_img;
	//void	*enemy;
	
	
}				t_game;

void	error_message(char *str);
void	convert_map_to_array(int fd, t_game *game);
void	check_map_params(t_game *game);
void	make_window(t_game *game);
void	put_img(t_game *game, void *path, int x, int y);

int		key_hook(int keycode, t_game *game);
int		close_game(t_game *game);

#endif
