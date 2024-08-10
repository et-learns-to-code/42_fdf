/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:12:59 by etien             #+#    #+#             */
/*   Updated: 2024/08/10 15:33:00 by etien            ###   ########.fr       */
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
	int	**z;
	int	**color;
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
