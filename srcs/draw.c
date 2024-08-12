/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:00:00 by etien             #+#    #+#             */
/*   Updated: 2024/08/12 11:30:57 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// This function will store the color integer at the image pixel address
// and achieve the effect of placing a pixel on the image.
// data_addr is the pointer to the first pixel in the image.
// (y * fdf->size_line) will be the y-offset while
// (x * (fdf->bits_per_pixel / 8) will be the x-offset (1 byte = 8 bits)
// to get to the relevant pixel and store the RGB value there.
// *(unsigned int*)dst assumes a 32-bit color value.
// We use unsigned int because color values are inherently positive.
// Negative color values are undefined and could lead to unexpected behaviour.
void	put_pixel_on_img(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < IMG_WIDTH
		&& y >= 0 && y < IMG_HEIGHT)
	{
		dst = fdf->data_addr
			+ (y * fdf->size_line)
			+ (x * (fdf->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	draw(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			draw_line()
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}


int	get_index(int x, int y, int width)
{
	return (y * width + x);
}

t_point	create_point(t_map *map, int x, int y)
{
	t_point	point;
	int		index;

	index = get_index(x, y, map->width);
	point.x = x;
	point.y = y;
	point.z = map->z_arr[index];
	if (map->color_arr[index] == -1)
		point.color = DEFAULT_COLOR;
	else
		point.color = map->color_arr[index];
	return (point);
}
