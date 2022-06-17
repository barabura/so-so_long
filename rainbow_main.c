/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:36:46 by baura             #+#    #+#             */
/*   Updated: 2022/05/18 14:50:57 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <mlx.h>

/* MINILIBX STRUCTURE*/
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x = 0;
	int		y = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "rainbow");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (y <= 1079)
	{
		while (x <= 490)
		{
			while (x <= 69)
			{
				my_mlx_pixel_put(&img, x, y, 0x00FF0000);
				x++;
			}
			while (x <= 139)
			{
				my_mlx_pixel_put(&img, x, y, 0x00f2641d);
				x++;
			}
			while (x <= 209)
			{
				my_mlx_pixel_put(&img, x, y, 0x00eff21d);
				x++;
			}
			while (x <= 279)
			{
				my_mlx_pixel_put(&img, x, y, 0x0000FF00);
				x++;
			}
			while (x <= 349)
			{
				my_mlx_pixel_put(&img, x, y, 0x001dcff2);
				x++;
			}
			while (x <= 419)
			{
				my_mlx_pixel_put(&img, x, y, 0x000000FF);
				x++;
			}
			while (x <= 490)
			{
				my_mlx_pixel_put(&img, x, y, 0x006b1df2);
				x++;
			}
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

// gcc -Wall -Wextra -Werror rainbow_main.c -Lmlx -lmlx -framework OpenGL -framework AppKit -o rainbow

// 0x00FF0000 - red
// 0x00f2641d - orange
// 0x00eff21d - yellow
// 0x0000FF00 - green
// 0x001dcff2 - light blue
// 0x000000FF - blue
// 0x006b1df2 - purple
