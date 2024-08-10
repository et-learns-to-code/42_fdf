/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:35:06 by etien             #+#    #+#             */
/*   Updated: 2024/08/10 12:26:45 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
// library for boolean data type
# include <stdbool.h>
// library for open function
# include <fcntl.h>
# include "keyboard_macros.h"
# include "../libft/libft/libft.h"

# define WIDTH 1000
# define HEIGHT 1000

# define ARG_ERR "Usage: './fdf file.fdf'"
# define FILENAME_ERR "Error: File should end with '.fdf' extension"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	int	width;
	int	height;
	int **z;
	int **color;
}	t_map;

typedef enum projection
{
	ISOMETRIC,
	PARALLEL
}	t_projection;

typedef struct s_view
{
	t_projection	projection;
	int				zoom;
	int				x_offset;
	int				y_offset;
	double			alpha;
	double			beta;
	double			gamma;
}	t_view;

#endif
