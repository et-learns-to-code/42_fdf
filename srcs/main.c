/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:26:44 by etien             #+#    #+#             */
/*   Updated: 2024/08/10 13:35:00 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct fdf
{
	void *mlx;
	void *win;
}	t_fdf;


void	free_exit(t_fdf *fdf) {
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

int	handle_key(int keycode, t_fdf *fdf) {
	if (keycode == ESC_KEY)
		free_exit(fdf);
	printf("keycode %d\n", keycode);
	return (0);
}

// int main()
// {
// 	t_fdf fdf;
// 	int x = 0;
// 	int y = 0;

// 	fdf.mlx = mlx_init();
// 	fdf.win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "Fil de Fer");

// 	while (x < 100)
// 	{
// 		while (y < 100)
// 		{
// 			mlx_pixel_put(fdf.mlx, fdf.win, x, y, 0xffffff);
// 			y++;
// 		}
// 		mlx_pixel_put(fdf.mlx, fdf.win, x, y, 0xffffff);
// 		x++;
// 	}

// 	x = 0;
// 	y = 0;
// 	int color = 0xff0000;
// 	while (x < 100 && y < 100)
// 	{
// 		mlx_pixel_put(fdf.mlx, fdf.win, x, y, color);
// 		x++;
// 		y++;
// 	}


// 	mlx_key_hook(fdf.win, &handle_key, &fdf);
// 	mlx_loop(fdf.mlx);
// 	return (0);
// }

// a: starting point
// b: ending point
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
// (which is the reason for two if conditions, rather than else if)
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
void draw_line(t_point a, t_point b, t_fdf *fdf)
{
	t_point delta;
	t_point sign;
	t_point current;
	int error[2];

	delta.x = ft_abs(a.x - b.x);
	delta.y = ft_abs(a.y - b.y);
	sign.x = (b.x > a.x) ? 1 : -1;
	sign.y = (b.y > a.y) ? 1 : -1;
	error[0] = delta.x - delta.y;
	current = a;
	while (current.x != b.x || current.y != b.y)
	{
		put_pixel(fdf, current.x, current.y);
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			current.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			current.y += sign.y;
		}
	}
}

// This function will return the absolute value
// of the given number.
int ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return nbr;
}

// This function will check that the file inputted as the argument
// ends with the required extension of ".fdf".
// It will check the difference in length in the filename and extension,
// and move the filename's pointer to the position where the extension
// is expected to start.
// If the filename is longer than the extension and the comparison evaluates
// to 0 (i.e. no difference), the function will return true.
// Otherwise, it will return false.
bool	check_file_extension(const char *filename)
{
	const char	*extension = ".fdf";
	size_t		len_filename;
	size_t		len_extension;

	len_filename = ft_strlen(filename);
	len_extension = ft_strlen(extension);
	return (len_filename > len_extension
		&& ft_strncmp(filename + (len_filename - len_extension),
			extension, len_extension) == 0);
}

// This function will print the error message to STDERR
// and exit the program.
void err_and_exit(char *err_msg)
{
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(1);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		if (check_file_extension(av[1]))
			ft_printf("good file name\n");
		else
			err_and_exit(FILENAME_ERR);
	}
	else
		err_and_exit(ARG_ERR);
	return (0);
}
