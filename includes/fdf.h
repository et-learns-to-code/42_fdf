/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:35:06 by etien             #+#    #+#             */
/*   Updated: 2024/08/12 11:22:24 by etien            ###   ########.fr       */
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
# define WIN_WIDTH 1400
# define WIN_HEIGHT 800
# define IMG_WIDTH 1000
# define IMG_HEIGHT 800
# define PANEL_WIDTH 400
# define PANEL_HEIGHT 800

#define PANEL_TEXT 0x8F00FF

#define DEFAULT_COLOR 0xFFFFFF

// Error message macros
# define ARG_ERR "Usage: './fdf file.fdf'."
# define FILENAME_ERR "Error: File should end with '.fdf' extension."
# define FDF_INIT_ERR "Error: An error occurred while initialising \
	the fdf struct."
# define VIEW_INIT_ERR "Error: An error occurred while initialising \
	the view struct."

// Map parsing functions
bool	check_file_extension(const char *filename);

// Structs initialisation functions
t_view	*view_init();
t_fdf	*fdf_init(t_map *map, t_view *view);

// Bresenham line drawing algorithm functions
void	draw_line(t_point a, t_point b, t_fdf *fdf);
int		ft_abs(int nbr);
void	determine_step(t_point *sign, t_point a, t_point b);

// Drawing functions
void	put_pixel_on_img(t_fdf *fdf, int x, int y, int color);

// Error handling functions
void	err_and_exit(char *err_msg);
void	cleanup_and_exit(t_fdf *fdf, char *err_msg);

int		key_press(int key, t_fdf *fdf);

#endif
