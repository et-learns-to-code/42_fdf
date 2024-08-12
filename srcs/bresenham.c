/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:20:38 by etien             #+#    #+#             */
/*   Updated: 2024/08/12 15:28:51 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// This line drawing function employs Bresenham's algorithm
// to approximate a true line when plotting the pixels onto
// the image. The error term (which is the distance between
// the current point and where it's true point lies) is adjusted
// for every subsequent pixel and will determine the increment of
// x/y/both for a particular pixel.
// The function runs a while loop for plotting pixels until
// x and y are incremented to their final point (b).
// A pixel is placed first before checking the decision parameters:
// 	1) (error[0] * 2) > dx
// 	2) (error[0] * 2) < -dy
// Based on the different decision parameters, either x/y/both
// (increment for both x and y is why two if conditions are necessary,
// rather than using a simple else if statement)
// will be incremented and the error term will be adjusted accordingly.
// error[0] is the error term and error[1] is (error[0] * 2) used
// in the decision parameter.
// Calculation of absolute values, determination of sign directions,
// and using '!=' in the while loop condition (rather than '<' or '>')
// are done to ensure the line drawing function correctly handles
// all cases of slopes, including both positive and negative slopes,
// as well as steep and shallow lines.
// '||' means while loop will run until BOTH coordinates equal
// the coordinates of the final point.
void	draw_line(t_point start, t_point end, t_fdf *fdf)
{
	t_point	delta;
	t_point	step;
	t_point	current;
	int		error[2];

	delta.x = ft_abs(end.x - start.x);
	delta.y = ft_abs(end.y - start.y);
	determine_step(start, end, &step);
	error[0] = delta.x - delta.y;
	current = start;
	while (current.x != end.x || current.y != end.y)
	{
		put_pixel_on_img(current.x, current.y, get_gradient_color(current, start, end, delta), fdf);
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			current.x += step.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			current.y += step.y;
		}
	}
}

// This function will return the absolute value of the given number.
int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

// This function will determine the x and y step directions.
void	determine_step(t_point start, t_point end, t_point *step)
{
	if (end.x > start.x)
		step->x = 1;
	else
		step->x = -1;
	if (end.y > start.y)
		step->y = 1;
	else
		step->y = -1;
}
