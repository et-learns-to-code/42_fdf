/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:30:15 by etien             #+#    #+#             */
/*   Updated: 2024/08/22 16:04:18 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// This function initializes the map struct.
t_map	*map_init(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		err_and_exit(MAP_INIT_ERR);
	map->width = 0;
	map->height = 0;
	map->z_arr = NULL;
	map->color_arr = NULL;
	map->z_min = 0;
	map->z_max = 0;
	map->z_range = 0;
	return (map);
}

// This function initializes the view struct.
// If the view struct fails to be malloc'd, the
// previously allocated map struct has to be freed first.
t_view	*view_init(t_map *map)
{
	t_view	*view;

	view = malloc(sizeof(t_view));
	if (!view)
		free_map_and_exit(map, VIEW_INIT_ERR);
	view->projection = ISOMETRIC;
	view->parallel_view = TOP_VIEW;
	initialise_zoom(map, view);
	view->zoom = view->initial_zoom;
	view->x_offset = 0;
	view->y_offset = 0;
	view->alpha = 0;
	view->beta = 0;
	view->gamma = 0;
	return (view);
}

// This function will set the initial_zoom variable in the view struct.
// The zoom factor has to be initialised to fit the entire map
// within the window upon first render. The lower of zoom_x/zoom_y
// will be chosen as the starting zoom factor.
// Isometric projections will appear to scale each axis by a factor of sqrt(2).
// To estimate max_width and max_height, we round up the scaling factor to 2
// to simplify working with integers.
void	initialise_zoom(t_map *map, t_view *view)
{
	int		zoom_x;
	int		zoom_y;
	int		max_width;
	int		max_height;

	max_width = map->width * 2;
	max_height = map->height * 2;
	zoom_x = (WIN_WIDTH - 2 * MARGIN) / max_width;
	zoom_y = (WIN_HEIGHT - 2 * MARGIN) / max_height;
	if (zoom_x < zoom_y)
		view->initial_zoom = zoom_x;
	else
		view->initial_zoom = zoom_y;
	if (view->initial_zoom < 5)
		view->initial_zoom = 5;
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
t_fdf	*fdf_init(t_map *map, t_view *view, char **av)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		free_map_and_exit(map, FDF_INIT_ERR);
	fdf->map = map;
	fdf->view = view;
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
	return (fdf);
}
