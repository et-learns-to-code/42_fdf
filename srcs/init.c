/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:30:15 by etien             #+#    #+#             */
/*   Updated: 2024/08/12 16:32:15 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_view	*view_init(void)
{
	t_view	*view;

	view = malloc(sizeof(t_view));
	if (!view)
		err_and_exit(VIEW_INIT_ERR);
	view->projection = ISOMETRIC;
	view->zoom = 1;
	view->x_offset = 0;
	view->y_offset = 0;
	view->alpha = 0;
	view->beta = 0;
	view->gamma = 0;
	return (view);
}

// This function initializes the fdf struct.
// Initialization steps:
// 1) Obtain fdf struct pointer via malloc.
// 2) Obtain mlx connection pointer.
// 3) Obtain window pointer.
// 4) Obtain image pointer (metadata of entire image).
// 5) Obtain image data address pointer (actual pixel data of image).
// At every step, check that the pointer is actually received, if not
// error and exit the program.
// mlx_get_data_addr() will automatically set the bits_per_pixel, size_line
// and endian values for you.
t_fdf	*fdf_init(t_map *map, t_view *view)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		err_and_exit(FDF_INIT_ERR);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		cleanup_and_exit(fdf, FDF_INIT_ERR);
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "Fil de Fer");
	if (!fdf->win)
		cleanup_and_exit(fdf, FDF_INIT_ERR);
	fdf->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->img)
		cleanup_and_exit(fdf, FDF_INIT_ERR);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->size_line), &(fdf->endian));
	if (!fdf->data_addr)
		cleanup_and_exit(fdf, FDF_INIT_ERR);
	fdf->map = map;
	fdf->view = view;
	return (fdf);
}
