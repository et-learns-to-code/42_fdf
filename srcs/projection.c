/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:53:45 by etien             #+#    #+#             */
/*   Updated: 2024/08/14 14:35:08 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// These three functions will modify the coordinates for rotation
// around the x, y and z axes.
// double data type used for trigonometric functions
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

// This function will convert the coordinates to their correct
// positions for the isometric projection.
// We are creating the isometric illusion on a 2D space,
// so only x and y coordinates are affected.
// The z coordinate is merely used as a part of the calculation.
// z is subtracted from the y coordinate to add depth.
void	convert_to_isometric(int *x, int *y, int z)
{
	double iso_radian;
	int original_x;

	iso_radian = 0.5235987756;
	original_x = *x;
	*x = (*x - *y) * cos(iso_radian);
	*y = (original_x + *y) * sin(iso_radian) - z;
}

t_point	project_point(t_point p)
{

}
