/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:22:03 by etien             #+#    #+#             */
/*   Updated: 2024/08/26 17:06:28 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// There are four main error handling functions.
// Their use cases will depend on when the error arises
// within the program flow.
// 1) err_and_exit will be called if no structs have been
//    initialized yet.
// 2) free_map_and_exit will be called if only the map struct
//    has been initialized.
// 3) free_map_view_and_exit will be called if both the map and
//    view structs have been initialized but the fdf struct fails
//    to be initialized.
// 4) free_fdf_and_exit will be called if the fdf struct has been
//    initialized and the map and view structs have already been
//    assigned to it.

// This function will print the error message to STDERR
// and exit the program.
void	err_and_exit(char *err_msg)
{
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(1);
}

// This is a separate cleanup function used in the early
// stages of map parsing. At this stage, the fdf struct
// has not been initialized yet, so this cleanup function
// will handle for cases where error is encountered when
// setting up the map struct and early exit is necessary.
void	free_map_and_exit(t_map *map, char *err_msg)
{
	if (map)
	{
		if (map->z_arr)
			free(map->z_arr);
		if (map->color_arr)
			free(map->color_arr);
		free(map);
	}
	err_and_exit(err_msg);
}

// This function will free both the map and view struct for the
// specific case when fdf has not been successfully initialized.
void	free_map_view_and_exit(t_map *map, t_view *view, char *err_msg)
{
	if (map)
	{
		if (map->z_arr)
			free(map->z_arr);
		if (map->color_arr)
			free(map->color_arr);
		free(map);
	}
	if (view)
		free(view);
	err_and_exit(err_msg);
}

// This function will free all allocated memory within the fdf struct
// and error-exit the program. It will clean up all the pointers when
// an error is encountered to prevent memory leaks.
// The pointers have to be freed in the order of LIFO because of the way
// they are dependent on each other.
// Sequence: image > window > mlx connection > fdf struct
// - image and window have dedicated functions for cleanup.
// - mlx pointer has to be freed manually.
// - data_addr pointer doesn't have to be freed because it was not malloc'd
//   in the first place (see actual function in Minilibx).
// The if else statement at the end allows for flexibility so that this
// function becomes a general cleanup function. If no error message is
// provided, it will exit with status 0 (normal exit).
void	free_fdf_and_exit(t_fdf *fdf, char *err_msg)
{
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
		free(fdf->mlx);
	if (fdf)
	{
		if (fdf->map)
		{
			if (fdf->map->z_arr)
				free(fdf->map->z_arr);
			if (fdf->map->color_arr)
				free(fdf->map->color_arr);
			free(fdf->map);
		}
		if (fdf->view)
			free(fdf->view);
		free(fdf);
	}
	if (err_msg)
		err_and_exit(err_msg);
	else
		exit(0);
}

// A helper function to free double arrays for proper memory management.
// This function is called in the parse_line function to free the
// splitted line after it has been processed.
void	free_double_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}
