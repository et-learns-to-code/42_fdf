/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:06:38 by etien             #+#    #+#             */
/*   Updated: 2024/08/12 16:29:33 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// This function will modify and recombine the RGB values of the current point
// based on its relative position to the start and end points in order to
// produce a color gradient effect when the line is plotted.
// Bitwise operation is used to separate out the RGB color components for
// modification and also to recombine them later on.
// '& 0xFF' extracts the least significant byte (the last 8 bits) from a
// 32-bit integer.
// delta has to be inputted to the function, because we want to choose the
// larger of delta-x or delta-y, so that the gradient is spread out over
// a greater distance and appears smoother.
int	get_gradient_color(t_point current, t_point start, t_point end,
	t_point delta)
{
	double	relative_position;
	int		red;
	int		green;
	int		blue;

	if (delta.x > delta.y)
		relative_position = get_relative_position(current.x, start.x, end.x);
	else
		relative_position = get_relative_position(current.y, start.y, end.y);
	red = modify_color_component((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, relative_position);
	green = modify_color_component((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, relative_position);
	blue = modify_color_component(start.color & 0xFF,
			end.color & 0xFF, relative_position);
	return (red << 16 | green << 8 | blue);
}

// This function will return the relative position of the current point
// to its start and end points.
// The returned relative position will be a value between 0 and 1.
// Relative position closer to 0 means current point is closer to
// the start point.
// Relative position closer to 1 means current point is closer to
// the end point.
// if (distance == 0) check is to avoid division by zero.
// double data type used for precision in calculation to create
// a smoother gradient.
double	get_relative_position(int current, int start, int end)
{
	double	distance;
	double	position;

	distance = end - start;
	position = current - start;
	if (distance == 0)
		return (1);
	else
		return (position / distance);
}

// This function will modify the color component values based on the
// current point's relative position.
// Start and end here will be the isolated color component values of the
// start and end points respectively.
// Start is multiplied by (1 - relative_position) so that the start value
// has a greater weightage if the current point is closer to the start point
// (relative position value closer to 0).
// End is multiplied by (relative_position) so that the end value has a
// greater weightage if the current point is closer to the end point
// (relative position value closer to 1).
// The color components will be recombined back into the color
// (which will be an int), hence int data type is returned here.
int	modify_color_component(int start, int end, double relative_position)
{
	return ((int)((start * (1 - relative_position))
		+ (end * relative_position)));
}
