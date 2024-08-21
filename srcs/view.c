/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:25:32 by etien             #+#    #+#             */
/*   Updated: 2024/08/19 22:57:13 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// This function will increase or decrease the zoom on the 3D object by
// multiplying or dividing the previous zoom factor by a constant zoom factor.
// This ensures smoother zooming that is proportional to high and low
// levels of zoom.
// + 0.5 before casting ensures proper rounding to the nearest integer
// (round upwards if decimal is above 0.5).
// Max zoom: (5 * initial_zoom)
// Min zoom: 5 (due to division by 1.1 constant zoom and + 0.5 rounding,
// the zoom will mathematically bottom out at 5.)
// Zoom cannot be 0 or negative otherwise object won't render.
void	zoom(int key, t_fdf *fdf)
{
	double	zoom_factor;
	int		max_zoom;

	zoom_factor = 1.1;
	max_zoom = fdf->view->initial_zoom * 5;
	if (key == PLUS_KEY)
	{
		fdf->view->zoom = (int)(fdf->view->zoom * zoom_factor + 0.5);
		if (fdf->view->zoom > max_zoom)
			fdf->view->zoom = max_zoom;
	}
	else if (key == MINUS_KEY)
	{
		fdf->view->zoom = (int)(fdf->view->zoom / zoom_factor + 0.5);
	}
	draw(fdf->map, fdf);
}

// This function will modify the x and y offsets depending
// on the arrow keys pressed to move the 3D object.
// The up key decreases the y offset and the down key increases
// it because the y-axis is flipped in minilibx.
// x and y offsets are in pixel units.
// The move_step is modified based on the zoom level.
// This ensures that the movement step is always proportional
// to the zoom and solves the issue of slow movement of the object
// across the screen when the zoom level is high.
void	move(int key, t_fdf *fdf)
{
	int move_step;

	move_step = 15 * fdf->view->zoom / fdf->view->initial_zoom;
	if (key == UP_KEY || key == W_KEY)
		fdf->view->y_offset -= move_step;
	else if (key == DOWN_KEY || key == S_KEY)
		fdf->view->y_offset += move_step;
	else if (key == LEFT_KEY || key == A_KEY)
		fdf->view->x_offset -= move_step;
	else if (key == RIGHT_KEY || key == D_KEY)
		fdf->view->x_offset += move_step;
	draw(fdf->map, fdf);
}

// This function will modify the alpha, beta and gamma values to
// achieve rotation of the 3D object around the x, y and z axes
// respectively.
// alpha, beta and gamma are radian values, so 0.1 will be a
// reasonable step for adjustment.
// The keycodes are not random, but are mapped out for more
// intuitive controls. Opposite rotations will be symmetrical
// in finger placement on the keyboard.
void	rotate(int key, t_fdf *fdf)
{
	if (key == NUM_3_KEY)
		fdf->view->alpha += 0.1;
	else if (key == NUM_7_KEY)
		fdf->view->alpha -= 0.1;
	else if (key == NUM_2_KEY)
		fdf->view->beta += 0.1;
	else if (key == NUM_8_KEY)
		fdf->view->beta -= 0.1;
	else if (key == NUM_1_KEY)
		fdf->view->gamma += 0.1;
	else if (key == NUM_9_KEY)
		fdf->view->gamma -= 0.1;
	draw(fdf->map, fdf);
}

// This function will reset all rotation to neutral angles then
// set the projection type to isometric or parallel.
void	change_projection(int key, t_fdf *fdf)
{
	fdf->view->alpha = 0;
	fdf->view->beta = 0;
	fdf->view->gamma = 0;
	if (key == I_KEY)
		fdf->view->projection = ISOMETRIC;
	else if (key == P_KEY)
	{
		fdf->view->projection = PARALLEL;
		change_parallel_view(fdf);
	}
	draw(fdf->map, fdf);
}

// This function is a helper function of the change projection function.
// Each time the P key is pressed, the parallel view will cycle to the
// next one in the sequence: top > front > side.
// 90 degrees = 1.57079632679 radians
void	change_parallel_view(t_fdf *fdf)
{
	double			parallel_radian;
	t_parallel_view	direction;

	parallel_radian = 1.57079632679;
	direction = fdf->view->parallel_view;
	if (direction == TOP_VIEW)
	{
		fdf->view->alpha = 0;
		fdf->view->beta = 0;
		fdf->view->gamma = 0;
	}
	else if (direction == FRONT_VIEW)
	{
		fdf->view->alpha = parallel_radian;
		fdf->view->beta = 0;
		fdf->view->gamma = 0;
	}
	else if (direction == LEFT_SIDE_VIEW)
	{
		fdf->view->alpha = 0;
		fdf->view->beta = -parallel_radian;
		fdf->view->gamma = parallel_radian;
	}
	fdf->view->parallel_view = (direction + 1) % 3;
	draw(fdf->map, fdf);
}
