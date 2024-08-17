/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:25:32 by etien             #+#    #+#             */
/*   Updated: 2024/08/17 12:10:20 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// This function will increase or decrease the zoom on the 3D object.
// ++ or -- to modify the zoom factor (which will be multiplied
// with each coordinate).
void	zoom(int key, t_fdf *fdf)
{
	if (key == PLUS_KEY)
	{
		fdf->view->zoom++;
		ft_printf("Zoom increased: %i\n", fdf->view->zoom);
	}
	else if (key == MINUS_KEY)
	{
		fdf->view->zoom--;
		ft_printf("Zoom decreased: %i\n", fdf->view->zoom);
	}
	draw(fdf->map, fdf);
}

// This function will modify the x and y offsets depending
// on the WASD keys pressed to move the 3D object.
// W decreases the y offset and S increases it because the
// y-axis is flipped in minilibx.
// x and y offsets are in pixel units.
void	move(int key, t_fdf *fdf)
{
	if (key == W_KEY)
		fdf->view->y_offset -= 15;
	else if (key == A_KEY)
		fdf->view->x_offset -= 15;
	else if (key == S_KEY)
		fdf->view->y_offset += 15;
	else if (key == D_KEY)
		fdf->view->x_offset += 15;
	draw(fdf->map, fdf);
}

// This function will modify the alpha, beta and gamma values to
// achieve rotation of the 3D object around the x, y and z axes
// respectively.
// alpha, beta and gamma are radian values, so 0.1 will be a
// reasonable step for adjustment.
void	rotate(int key, t_fdf *fdf)
{
	if (key == NUM_1_KEY)
		fdf->view->alpha += 0.1;
	else if (key == NUM_2_KEY)
		fdf->view->alpha -= 0.1;
	else if (key == NUM_3_KEY)
		fdf->view->beta += 0.1;
	else if (key == NUM_4_KEY)
		fdf->view->beta -= 0.1;
	else if (key == NUM_5_KEY)
		fdf->view->gamma += 0.1;
	else if (key == NUM_6_KEY)
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
void change_parallel_view(t_fdf *fdf)
{
	double parallel_radian;
	t_parallel_view direction;

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
}
