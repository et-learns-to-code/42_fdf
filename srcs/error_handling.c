/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:22:03 by etien             #+#    #+#             */
/*   Updated: 2024/08/12 16:32:29 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// This function will print the error message to STDERR
// and exit the program.
void	err_and_exit(char *err_msg)
{
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(1);
}

// This function cleans up all the pointers when an error is encountered
// to prevent memory leaks. The pointers have to be freed in the order of
// LIFO because of the way they are dependent on each other.
// Sequence: image > window > mlx connection > fdf struct
// image and window have dedicated functions for cleanup.
// mlx pointer has to be freed manually.
// data_addr pointer doesn't have to be freed because it was not malloc'd
// in the first place (see actual function in Minilibx).
void	cleanup_and_exit(t_fdf *fdf, char *err_msg)
{
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
		free(fdf->mlx);
	free(fdf);
	err_and_exit(err_msg);
}
