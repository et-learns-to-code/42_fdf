/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:35:06 by etien             #+#    #+#             */
/*   Updated: 2024/08/10 16:46:30 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// math.h - for float number math functions
// stdbool.h - for boolean data type
// fcntl.h - for file open function
# include <mlx.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include "structs.h"
# include "keyboard_macros.h"
# include "../libft/libft/libft.h"

// Width and height macros
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define IMG_WIDTH 800
# define IMG_HEIGHT 800

// Error message macros
# define ARG_ERR "Usage: './fdf file.fdf'"
# define FILENAME_ERR "Error: File should end with '.fdf' extension"
# define FDF_INIT_ERR "Error: An error occurred while initialising \
	the fdf struct"

// Bresenham line drawing algorithm functions
void	draw_line(t_point a, t_point b, t_fdf *fdf);
int		ft_abs(int nbr);
void	determine_step(t_point *sign, t_point a, t_point b);

// Util functions
void	err_and_exit(char *err_msg);
bool	check_file_extension(const char *filename);

#endif
