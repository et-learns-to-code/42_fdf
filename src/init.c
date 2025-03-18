/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:30:15 by etien             #+#    #+#             */
/*   Updated: 2025/03/18 09:36:40 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// This function initializes the view struct.
// Zoom has to be initialized to fit the entire top view within the map.
// Initial zoom cannot go below 5, otherwise the zoom in and out functions
// will be locked due to the 1.2 zoom factor that will bottom out at 3.
void	view_init(t_view *view, t_map *map)
{
	int	scale_x;
	int	scale_y;

	ft_bzero(view->keys, sizeof(view->keys));
	view->projection = PARALLEL;
	view->parallel_view = TOP_VIEW;
	view->initial_zoom = WIN_WIDTH / map->width / 3;
	if (view->initial_zoom < 5)
		view->initial_zoom = 5;
	scale_x = WIN_WIDTH / map->width;
	scale_y = WIN_HEIGHT / map->height;
	if (scale_x < scale_y)
		view->zoom = scale_x;
	else
		view->zoom = scale_y;
	view->x_offset = 0;
	view->y_offset = 0;
	view->alpha = 0;
	view->beta = 0;
	view->gamma = 0;
	view->cos_iso = cos(ISO_RADIAN);
	view->sin_iso = sin(ISO_RADIAN);
}

// This function initializes the fdf struct.
// Initialization steps:
// 1) Obtain fdf struct pointer via malloc.
// 2) Map and view structs are assigned to the fdf struct ASAP
//    to make use of the free_fdf_and_exit function.
// 3) Obtain mlx connection pointer.
// 4) Obtain window pointer.
// 5) Obtain image pointer (metadata of entire image).
// 6) Obtain image data address pointer (actual pixel data of image).
// At every step, check that the pointer is actually received, if not
// free the fdf struct and exit the program.
// mlx_get_data_addr() will automatically set the bits_per_pixel, size_line
// and endian values for you.
void	fdf_init(t_fdf *fdf, char **av)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		free_fdf_and_exit(fdf, FDF_INIT_ERR);
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, av[1]);
	if (!fdf->win)
		free_fdf_and_exit(fdf, FDF_INIT_ERR);
	fdf->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->img)
		free_fdf_and_exit(fdf, FDF_INIT_ERR);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->size_line), &(fdf->endian));
	if (!fdf->data_addr)
		free_fdf_and_exit(fdf, FDF_INIT_ERR);
}
