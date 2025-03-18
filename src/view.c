/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:25:32 by etien             #+#    #+#             */
/*   Updated: 2025/03/18 09:32:46 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// This function will increase or decrease the zoom on the object by
// multiplying or dividing the previous zoom factor by a constant zoom factor.
// This ensures smoother zooming that is proportional to high and low
// levels of zoom.
// + 0.5 before casting ensures proper rounding to the nearest integer
// (round upwards if decimal is above 0.5).
// Max zoom: (10 * initial_zoom)
// Min zoom: 3 (due to division by 1.2 constant zoom and + 0.5 rounding,
// the zoom will mathematically bottom out at 3.)
// Zoom cannot be 0 or negative otherwise the object won't render.
void	zoom(int *keys, t_fdf *fdf, int *update_view)
{
	double	zoom_factor;
	int		max_zoom;

	*update_view = 1;
	zoom_factor = 1.2;
	max_zoom = fdf->view.initial_zoom * 10;
	if (keys[PLUS_KEY])
	{
		fdf->view.zoom = (int)(fdf->view.zoom * zoom_factor + 0.5);
		if (fdf->view.zoom > max_zoom)
			fdf->view.zoom = max_zoom;
	}
	if (keys[MINUS_KEY])
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
void	move(int *keys, t_fdf *fdf, int *update_view)
{
	int	move_step;

	*update_view = 1;
	move_step = 15 * fdf->view.zoom / fdf->view.initial_zoom;
	if (keys[W_KEY])
		fdf->view.y_offset -= move_step;
	if (keys[S_KEY])
		fdf->view.y_offset += move_step;
	if (keys[A_KEY])
		fdf->view.x_offset -= move_step;
	if (keys[D_KEY])
		fdf->view.x_offset += move_step;
}

// This function will modify the alpha, beta and gamma values to
// achieve rotation of the object around the x, y and z axes
// respectively.
// alpha, beta and gamma are radian values, so 0.1 will be a
// reasonable step for adjustment.
// The keycodes are not random, but are mapped out for more
// intuitive controls. Opposite rotations will be symmetrical
// in finger placement on the keyboard.
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
}

// This function will reset all rotation to neutral angles then
// set the projection type to isometric or parallel.
void	change_projection(int *keys, t_fdf *fdf, int *update_view)
{
	*update_view = 1;
	fdf->view.alpha = 0;
	fdf->view.beta = 0;
	fdf->view.gamma = 0;
	if (keys[I_KEY])
		fdf->view.projection = ISOMETRIC;
	else if (keys[P_KEY])
	{
		fdf->view.projection = PARALLEL;
		change_parallel_view(fdf);
	}
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
