/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:45 by baura             #+#    #+#             */
/*   Updated: 2022/06/18 18:39:31 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *str)
{
	ft_putstr_fd("Error: ", STDERR_FILENO); //STDERR_FILENO
	ft_putstr_fd(str, STDERR_FILENO);
	write(1, "\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	init_game(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->player = 0;
	game->colletctible = 0;
	game->exit = 0;
	game->steps = 0;
}

void	check_argument(char *arg)
{
	if (ft_strnstr(arg, ".ber", 4) == 0)
		error_message("Your map must have .ber file extension");
}

/* init image */
char	*open_image(char *path)
{
	if (open(path, O_RDONLY) < 0)
		error_message("Image opening error");
	return (path);
}

void	init_images(t_game *game)
{
	game->img_size = 100;
	game->empty_space_img = open_image("./imgs/background.xpm");
	game->wall_img = open_image("./imgs/box.xpm");
	game->collectable_img = open_image("./imgs/coin_1.xpm");
	game->player_img = open_image("./imgs/cat_1.xpm");
	game->exit_img = open_image("./imgs/exit.xpm");
}

/* fill window */
void	put_img(t_game *game, void *path, int x, int y)
{
	game->img_ptr = mlx_xpm_file_to_image(game->mlx, path, &game->img_size, &game->img_size);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_ptr, x, y);
	//mlx_loop(game->mlx);
}

/* moving image */

void	fill_window(t_game *game)
{
	int	w;
	int	h;
	
	h = 0;
	while (h < game->height)
	{
		w = 0;
		while (game->map[h][w])
		{
			if (game->map[h][w] == '1')
				put_img(game, game->wall_img, w * game->img_size, h * game->img_size);
			if (game->map[h][w] == '0')
				put_img(game, game->empty_space_img, w * game->img_size, h * game->img_size);
			if (game->map[h][w] == 'C')
			{
				put_img(game, game->empty_space_img, w * game->img_size, h * game->img_size);
				put_img(game, game->collectable_img, w * game->img_size, h * game->img_size);
			}
			if (game->map[h][w] == 'P')
				put_img(game, game->player_img, w * game->img_size, h * game->img_size);
			if (game->map[h][w] == 'E')
				put_img(game, game->exit_img, w * game->img_size, h * game->img_size);
			w++;
		}
		h++;
	}
}

void	make_window(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->width * game->img_size, \
					game->height * game->img_size, "so_long");
	fill_window(game);
}


int	main(int argc, char **argv)
{
	t_game	game;
	int 	fd = 0;
	//int		i = 0;
		
	if (argc < 2)
		error_message("You must use a map to start the game");
	if (argc > 2)
		error_message("Excessive number of arguments. You can use only 1 map at a time");
	if (argc == 2)
		check_argument(argv[1]);
	init_game(&game);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_message("Map opening error");
	convert_map_to_array(fd, &game);
	check_map_params(&game);
	
	init_images(&game);
	make_window(&game);
	
	//mlx_key_hook(game.mlx_win, )
	
	//while (game.map[i] != NULL)
	//{
	//	ft_putstr_fd("map:", 1);
	//	ft_putstr_fd(game.map[i], 1);
	//	ft_putchar_fd('\n', 1);
	//	i++;
	//}

	//while (game.map[0][game.width] != '\0')
	//	game.width += 1;
	//printf("%d", game.width);
	mlx_loop(game.mlx);
	return (0);
}

//int	main(void)
//{
//	char	*line;
//	int		i;
//	int		fd1;
//	/*int		fd1;
//	int		fd2;
//	int		fd3;*/
//	//fd = 0;
//	fd1 = open("map.ber", O_RDONLY);
//	/*fd2 = open("tests/file2.txt", O_RDONLY);
//	fd3 = open("tests/file3.txt", O_RDONLY)*/
//	i = 1;
//	while (i < 7)
//	{
//		line = get_next_line(fd1);
//		ft_putstr_fd(line, 1);
//		//printf("line [%02d]: %s", i, line);
//		free(line);
//		/*line = get_next_line(fd1);
//		printf("line [%02d]: %s", i, line);
//		free(line);
//		line = get_next_line(fd2);
//		printf("line [%02d]: %s", i, line);
//		free(line);
//		line = get_next_line(fd3);
//		printf("line [%02d]: %s", i, line);
//		free(line);*/
//		i++;
//	}
//	close(fd1);
//	/*close(fd2);
//	close(fd3);*/
//	return (0);
//}
