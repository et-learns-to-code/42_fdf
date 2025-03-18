/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:25:32 by etien             #+#    #+#             */
/*   Updated: 2025/03/18 12:21:49 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// This function will increase or decrease the zoom on the object by
// multiplying or dividing the zoom by a constant zoom factor.
// This ensures smoother zooming.
// + 0.5 before casting ensures proper rounding to the nearest integer
// (round upwards if decimal is above 0.5).
// - max_zoom = 200 keeps zoom behavior uniform across different map sizes.
// - min_zoom (small maps) = 3 uses a gentler zoom factor for fine control.
// - min_zoom (large maps) = 1 uses a stronger zoom factor to navigate quickly.
void	zoom(int *keys, t_fdf *fdf, int *update_view)
{
	double	zoom_factor;
	double	max_zoom;
	double	min_zoom;

	*update_view = 1;
	max_zoom = 200;
	if (fdf->map.width <= 250 || fdf->map.height <= 250)
	{
		zoom_factor = 1.1;
		min_zoom = 3;
	}
	else
	{
		zoom_factor = 1.5;
		min_zoom = 1;
	}
	if (keys[PLUS_KEY])
		if (fdf->view.zoom < max_zoom)
			fdf->view.zoom = (int)(fdf->view.zoom * zoom_factor + 0.5);
	if (keys[MINUS_KEY])
		if (fdf->view.zoom > min_zoom)
			fdf->view.zoom = (int)(fdf->view.zoom / zoom_factor + 0.5);
}

// This function will modify the x and y offsets depending
// on the arrow keys pressed to move the object.
// The up key decreases the y offset and the down key increases
// it because the y-axis is flipped in minilibx.
// x and y offsets are in pixel units.
// The move_step is modified based on the zoom level.
// This ensures that the movement step is always proportional
// to the zoom and solves the issue of slow movement of the object
// across the screen when the zoom level is high.
// The 10 ensures a minimum movement step, so even at the smallest zoom level, 
// the object doesn't move too slowly.
void	move(int *keys, t_fdf *fdf, int *update_view)
{
	int	move_step;

	*update_view = 1;
	move_step = 10 + (fdf->view.zoom / 5);
	if (keys[W_KEY])
		fdf->view.y_offset += move_step;
	if (keys[S_KEY])
		fdf->view.y_offset -= move_step;
	if (keys[A_KEY])
		fdf->view.x_offset += move_step;
	if (keys[D_KEY])
		fdf->view.x_offset -= move_step;
}

// This function will modify the alpha, beta and gamma values to
// achieve rotation of the object around the x, y and z axes
// respectively.
// alpha, beta and gamma are radian values, so 0.1 will be a
// reasonable step for adjustment.
// The keycodes are not random, but are mapped out for more
// intuitive controls. Opposite rotations will be symmetrical
// in finger placement on the keyboard.
// alpha, beta and gamma are brought back to the range of 0 to 2PI.
void	rotate(int *keys, t_fdf *fdf, int *update_view)
{
	*update_view = 1;
	if (keys[NUM_3_KEY])
		fdf->view.alpha += 0.1;
	if (keys[NUM_7_KEY])
		fdf->view.alpha -= 0.1;
	if (keys[NUM_2_KEY])
		fdf->view.beta += 0.1;
	if (keys[NUM_8_KEY])
		fdf->view.beta -= 0.1;
	if (keys[NUM_1_KEY])
		fdf->view.gamma += 0.1;
	if (keys[NUM_9_KEY])
		fdf->view.gamma -= 0.1;
	if (fdf->view.alpha >= TWO_PI)
		fdf->view.alpha -= TWO_PI;
	else if (fdf->view.alpha < 0)
		fdf->view.alpha += TWO_PI;
	if (fdf->view.beta >= TWO_PI)
		fdf->view.beta -= TWO_PI;
	else if (fdf->view.beta < 0)
		fdf->view.beta += TWO_PI;
	if (fdf->view.gamma >= TWO_PI)
		fdf->view.gamma -= TWO_PI;
	else if (fdf->view.gamma < 0)
		fdf->view.gamma += TWO_PI;
}

// This function will reset all rotation to neutral angles then
// set the projection type to isometric or parallel.
void	change_projection(int key, t_fdf *fdf)
{
	fdf->view.alpha = 0;
	fdf->view.beta = 0;
	fdf->view.gamma = 0;
	if (key == I_KEY)
		fdf->view.projection = ISOMETRIC;
	else if (key == P_KEY)
	{
		fdf->view.projection = PARALLEL;
		change_parallel_view(fdf);
	}
	draw(&fdf->map, fdf);
}

// This function is a helper function of the change projection function.
// Each time the P key is pressed, the parallel view will cycle to the
// next one in the sequence: top > front > side.
// 90 degrees = 1.57079632679 radians
void	change_parallel_view(t_fdf *fdf)
{
	t_parallel_view	direction;

	direction = fdf->view.parallel_view;
	if (direction == TOP_VIEW)
	{
		fdf->view.alpha = 0;
		fdf->view.beta = 0;
		fdf->view.gamma = 0;
	}
	else if (direction == FRONT_VIEW)
	{
		fdf->view.alpha = PARALLEL_RADIAN;
		fdf->view.beta = 0;
		fdf->view.gamma = 0;
	}
	else if (direction == LEFT_SIDE_VIEW)
	{
		fdf->view.alpha = 0;
		fdf->view.beta = -PARALLEL_RADIAN;
		fdf->view.gamma = PARALLEL_RADIAN;
	}
	fdf->view.parallel_view = (direction + 1) % 3;
}
