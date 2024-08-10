/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:26:44 by etien             #+#    #+#             */
/*   Updated: 2024/08/10 11:44:07 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct fdf
{
	void *mlx;
	void *win;
}	t_fdf;


void	free_exit(t_fdf *fdf) {
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

int	handle_key(int keycode, t_fdf *fdf) {
	if (keycode == ESC_KEY)
		free_exit(fdf);
	printf("keycode %d\n", keycode);
	return (0);
}

int increment_color(int color, int step) {
    // Extract RGB components
    int red = (color >> 16) & 0xFF;
    int green = (color >> 8) & 0xFF;
    int blue = color & 0xFF;

    // Increment each color component
    red = (red + step) % 256;
    green = (green + step) % 256;
    blue = (blue + step) % 256;

    // Combine components back into a single color
    return (red << 16) | (green << 8) | blue;
}


int main()
{
	t_fdf fdf;
	int x = 0;
	int y = 0;

	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "Fil de Fer");

	while (x < 100)
	{
		while (y < 100)
		{
			mlx_pixel_put(fdf.mlx, fdf.win, x, y, 0xffffff);
			y++;
		}
		mlx_pixel_put(fdf.mlx, fdf.win, x, y, 0xffffff);
		x++;
	}

	x = 0;
	y = 0;
	int color = 0xff0000;
	while (x < 100 && y < 100)
	{
		mlx_pixel_put(fdf.mlx, fdf.win, x, y, color);
		x++;
		y++;
	}


	mlx_key_hook(fdf.win, &handle_key, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}

void draw_line(t_point a, t_point b)

// void err_and_exit(char *err_msg)
// {
// 	ft_putendl_fd(err_msg, STDERR_FILENO);
// 	exit(1);
// }


// int main(int ac, char **av)
// {
// 	(void) av;
// 	if (ac == 2)
// 	{
// 		if (av[1])
// 		exit(0);


// 	}
// 	err_and_exit(ARG_ERR);
// 	return (0);
// }

