/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:12:59 by etien             #+#    #+#             */
/*   Updated: 2024/08/19 15:22:16 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
	int	*z_arr;
	int	*color_arr;
	int	z_min;
	int	z_max;
	int	z_range;
}	t_map;

typedef enum projection
{
	ISOMETRIC,
	PARALLEL
}	t_projection;

typedef enum parallel_view
{
	TOP_VIEW,
	FRONT_VIEW,
	LEFT_SIDE_VIEW
}	t_parallel_view;

typedef struct s_view
{
	t_projection	projection;
	t_parallel_view	parallel_view;
	int				zoom;
	int				x_offset;
	int				y_offset;
	double			alpha;
	double			beta;
	double			gamma;
}	t_view;

// Bits per pixel, size_line and endian will be set up by the
// mlx_get_data_addr function.
// bits per pixel: number of bits used for each pixel in the image
// size_line: number of bytes per line of the image,
// 			including any padding bytes.
// endian: little-endian or big_endian - will affect how RGB data is stored
//			However, endian is inconsequential on MacOS because client and
//			graphical framework share same endian.
typedef struct fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_map	*map;
	t_view	*view;
}	t_fdf;

#endif
