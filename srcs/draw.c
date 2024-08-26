/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:00:00 by etien             #+#    #+#             */
/*   Updated: 2024/08/26 18:15:27 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// This is the main drawing function for the entire program.
// It will iterate through the map struct and draw all the lines
// that connect the points.
// (x + 1) and (y + 1) means that adjacent coordinates (to the right
// and below respectively) in the map should be connected together by lines.
// create_point: creates and sets up the data for point structs
// project_point: manipulates the data in the point structs
//                based on the info in the view structs
// draw_line: employs Bresenham's algorithm to draw lines between
//            the points and shades the lines with gradients.
void	draw(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	clear_image(fdf);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((x + 1) < map->width)
				draw_line(project_point(create_point(x, y, map), fdf),
					project_point(create_point(x + 1, y, map), fdf), fdf);
			if ((y + 1) < map->height)
				draw_line(project_point(create_point(x, y, map), fdf),
					project_point(create_point(x, y + 1, map), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

// This function will clear the image buffer by calling ft_bzero which
// will zero out all the pixel data. Since 0 = 0x000000 (black), this
// will set all the pixels to black, essentially clearing the screen.
// The dimensions input to ft_bzero will be the size of the window.
// WIN_WIDTH * WIN_HEIGHT is just the number of pixels.
// For ft_bzero to work, you still have to multiply by the number of bytes.
void	clear_image(t_fdf *fdf)
{
	ft_bzero(fdf->data_addr, (WIN_WIDTH * WIN_HEIGHT
			* (fdf->bits_per_pixel / 8)));
}

// This function will create the point structs that will be fed into
// the drawing function by extracting this data from the map struct.
// x and y are the map coordinates iterated through in the draw function.
// z and color will be fetched from the map arrays.
t_point	create_point(int x, int y, t_map *map)
{
	t_point	point;
	int		index;

	index = get_index(x, y, map->width);
	point.x = x;
	point.y = y;
	point.z = map->z_arr[index];
	point.color = map->color_arr[index];
	return (point);
}

// This function will return the index to access the correct element
// in the z_arr and color_arr.
int	get_index(int x, int y, int width)
{
	return (y * width + x);
}
