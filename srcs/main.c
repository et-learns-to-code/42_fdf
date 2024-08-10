/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:26:44 by etien             #+#    #+#             */
/*   Updated: 2024/08/10 15:38:44 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_exit(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

int	handle_key(int keycode, t_fdf *fdf)
{
	if (keycode == ESC_KEY)
		free_exit(fdf);
	ft_printf("keycode %d\n", keycode);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;
	t_point	a;
	t_point	b;

	if (ac == 2)
	{
		if (check_file_extension(av[1]))
			ft_printf("good file name\n");
		else
			err_and_exit(FILENAME_ERR);
		fdf.mlx = mlx_init();
		fdf.win = mlx_new_window(fdf.mlx, WIN_WIDTH, WIN_HEIGHT, "Fil de Fer");
		fdf.img = mlx_new_image(fdf.mlx, IMG_WIDTH, IMG_HEIGHT);
		a.x = 0;
		a.y = 0;
		b.x = 300;
		b.y = 300;
		draw_line(a, b, &fdf);
		mlx_key_hook(fdf.win, &handle_key, &fdf);
		mlx_loop(fdf.mlx);
	}
	else
		err_and_exit(ARG_ERR);
	return (0);
}
