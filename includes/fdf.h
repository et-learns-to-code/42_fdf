/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:35:06 by etien             #+#    #+#             */
/*   Updated: 2024/08/12 17:32:10 by etien            ###   ########.fr       */
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

# define PANEL_TEXT 0x8F00FF

# define DEFAULT_COLOR 0xFFFFFF

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
t_view	*view_init(void);
t_fdf	*fdf_init(t_map *map, t_view *view);

// Bresenham line drawing algorithm functions
void	draw_line(t_point start, t_point end, t_fdf *fdf);
void	set_delta(t_point start, t_point end, t_point *delta);
void	set_step(t_point start, t_point end, t_point *sign);

// Color functions
int		get_gradient_color(t_point current, t_point start, t_point end,
			t_point delta);
double	get_relative_position(int current, int start, int end);
int		modify_color_component(int start, int end, double relative_position);

// Drawing functions
void	put_pixel_on_img(int x, int y, int color, t_fdf *fdf);
void	draw(t_map *map, t_fdf *fdf);
int		get_index(int x, int y, int width);
t_point	create_point(int x, int y, t_map *map);

// Error handling functions
void	err_and_exit(char *err_msg);
void	cleanup_and_exit(t_fdf *fdf, char *err_msg);

// Set up hooks and callback functions
void	setup_hooks(t_fdf *fdf);
int		key_press(int key, t_fdf *fdf);
int		close_window(t_fdf *fdf);

#endif
