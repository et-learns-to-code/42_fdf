/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverted_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:45:38 by etien             #+#    #+#             */
/*   Updated: 2024/08/22 11:23:15 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	invert_colors(int key, t_fdf *fdf)
{
	int i;

	if (key == SPACE_BAR)
	{
		while (i < fdf->map->width * fdf->map->height)
		{
			fdf->map->color_arr[i] = get_inverted_color()
			i++;
		}
	}

	draw(fdf->map, fdf);
}

// This function will return the inverted color of the color
// given as a parameter.
// It will extract the RGB color components through bitwise shifts and
// invert each color component by subtracting the component's value from 255.
// After that, the color components are recombined into an integer that
// will represent the inverted color.
int	get_inverted_color(int color)
{
	int	red;
	int	green;
	int	blue;
	int inverted_color;

	red = (color >> 16) & 0xFF;
	green = (color >> 8) & 0xFF;
	blue = color & 0xFF;
	red = 255 - red;
	green = 255 - green;
	blue = 255 - blue;
	inverted_color = (red << 16) | (green << 8) | blue;
	return (inverted_color);
}


