/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:00:00 by etien             #+#    #+#             */
/*   Updated: 2024/08/19 17:10:14 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// This is the main drawing function for the entire program.
// It will iterate through the map struct and draw all the lines
// that connect the points.
void	draw(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	clear_image(fdf);
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

// This function will print out the side panel with usage instructions.
void	print_panel(t_fdf *fdf)
{
	int	x;
	int	x_indent;
	int	y;

	x = 15;
	x_indent = x + 50;
	y = 15;
	mlx_string_put(fdf->mlx, fdf->win, x, y, PANEL_TEXT, "Controls:");
	mlx_string_put(fdf->mlx, fdf->win, x, y, PANEL_TEXT, "Zoom: +/-");
	mlx_string_put(fdf->mlx, fdf->win, x, y, PANEL_TEXT, "Move: W A S D");
	mlx_string_put(fdf->mlx, fdf->win, x, y, PANEL_TEXT, "Rotate:");
	mlx_string_put(fdf->mlx, fdf->win, x_indent, y, PANEL_TEXT, "X-axis: 1/2");
	mlx_string_put(fdf->mlx, fdf->win, x_indent, y, PANEL_TEXT, "Y-axis: 3/4");
	mlx_string_put(fdf->mlx, fdf->win, x_indent, y, PANEL_TEXT, "Z-axis: 5/6");
	mlx_string_put(fdf->mlx, fdf->win, x, y, PANEL_TEXT, "Projection:");
	mlx_string_put(fdf->mlx, fdf->win, x_indent, y, PANEL_TEXT, "Isometric: I");
	mlx_string_put(fdf->mlx, fdf->win, x_indent, y, PANEL_TEXT, "Parallel: P");
}

// This function will create the point structs that will be fed into
// the drawing function by extracting this data from the map struct.
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
