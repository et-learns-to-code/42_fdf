/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:53:45 by etien             #+#    #+#             */
/*   Updated: 2024/08/26 18:40:12 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// This function will take into account all the view parameters to
// plot each point at its correct position.
// The sequence for transformation is important:
// Apply zoom > center at origin (0,0) > isometric projection > rotate
// > center in center of window > apply move offset
t_point	project_point(t_point p, t_fdf *fdf)
{
	p.x *= fdf->view->zoom;
	p.y *= fdf->view->zoom;
	p.z *= fdf->view->zoom;
	p.x -= (fdf->map->width * fdf->view->zoom / 2);
	p.y -= (fdf->map->height * fdf->view->zoom / 2);
	if (fdf->view->projection == ISOMETRIC)
		convert_to_isometric(&p.x, &p.y, p.z);
	rotate_x(&p.y, &p.z, fdf->view->alpha);
	rotate_y(&p.x, &p.z, fdf->view->beta);
	rotate_z(&p.x, &p.y, fdf->view->gamma);
	p.x += WIN_WIDTH / 2 + fdf->view->x_offset;
	p.y += WIN_HEIGHT / 2 + fdf->view->y_offset;
	return (p);
}

// This function will convert the coordinates to their correct
// positions for the isometric projection.
// We are creating the isometric illusion on a 2D space,
// so only x and y coordinates are affected.
// The z coordinate is merely used as a part of the calculation.
// z is subtracted from the y coordinate to add depth.
// 30 degrees = 0.52359877559 radians
void	convert_to_isometric(int *x, int *y, int z)
{
	double	iso_radian;
	int		original_x;

	iso_radian = 0.52359877559;
	original_x = *x;
	*x = (*x - *y) * cos(iso_radian);
	*y = (original_x + *y) * sin(iso_radian) - z;
}

// These three functions will modify the coordinates for rotation
// around the x, y and z axes.
// double data type used for trigonometric functions.
// float is 32-bit but double can represent floating numbers with
// 64-bit, meaning higher precision of values.
void	rotate_x(int *y, int *z, double alpha)
{
	int	original_y;

	original_y = *y;
	*y = *y * cos(alpha) - *z * sin(alpha);
	*z = original_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int	original_x;

	original_x = *x;
	*x = *x * cos(beta) + *z * sin(beta);
	*z = -original_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int	original_x;

	original_x = *x;
	*x = *x * cos(gamma) - *y * sin(gamma);
	*y = original_x * sin(gamma) + *y * cos(gamma);
}
