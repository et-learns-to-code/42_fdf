/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:25:32 by etien             #+#    #+#             */
/*   Updated: 2024/08/14 13:36:53 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// This function will increase or decrease the zoom on the 3D object.
// ++ or -- to modify the zoom factor (which will be multiplied
// with each coordinate).
void	zoom(int key, t_fdf *fdf)
{
	if (key == PLUS_KEY)
		fdf->view->zoom++;
	else if (key == MINUS_KEY)
		fdf->view->zoom--;
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
void change_projection(int key, t_fdf *fdf)
{
	fdf->view->alpha = 0;
	fdf->view->beta = 0;
	fdf->view->gamma = 0;
	if (key == I_KEY)
		fdf->view->projection = ISOMETRIC;
	else if (key == P_KEY)
		fdf->view->projection = PARALLEL;
	draw(fdf->map, fdf);
}
