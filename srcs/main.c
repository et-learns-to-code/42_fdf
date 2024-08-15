/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:26:44 by etien             #+#    #+#             */
/*   Updated: 2024/08/15 11:18:49 by etien            ###   ########.fr       */
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
	t_map	*map;
	t_view	*view;
	t_fdf	*fdf;
	t_point	a;
	t_point	b;

	map = NULL;
	if (ac == 2)
	{
		if (check_file_extension(av[1]))
		{
			map = map_init();
			get_map_height(av, map);
			get_map_width(av, map);
			ft_printf("Height: %d\n Width: %d\n", map->height, map->width);
		}
		else
			err_and_exit(FILE_NAME_ERR);
		view = view_init();
		fdf = fdf_init(map, view);
		a.x = 100;
		a.y = 100;
		a.color = 16777215;
		b.x = 400;
		b.y = 400;
		b.color = 0xff0000;
		draw_line(a, b, fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
		mlx_key_hook(fdf->win, &handle_key, &fdf);
		mlx_loop(fdf->mlx);
	}
	else
		err_and_exit(ARG_ERR);
	return (0);
}
