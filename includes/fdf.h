/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:35:06 by etien             #+#    #+#             */
/*   Updated: 2024/08/19 22:20:19 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// mlx.h - for MiniLibX library
// math.h - for trigonometric functions
// stdbool.h - for boolean data type
// fcntl.h - for file open function
# include <mlx.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include "structs.h"
# include "../libft/libft/libft.h"

// The relevant keycode header file will be included based on
// the operating system running.
// __linux__ and __APPLE__ macros are predefined by the compiler.
# ifdef __linux__
#  include "keycode_linux.h"
# elif __APPLE__
#  include "keycode_macos.h"
# else
#  error "Unsupported OS"
# endif

// Width and height macros
# define WIN_WIDTH 1400
# define WIN_HEIGHT 800
# define MARGIN 20
// # define IMG_WIDTH 1000
// # define IMG_HEIGHT 800
// # define PANEL_WIDTH 400
// # define PANEL_HEIGHT 800

# define PANEL_TEXT 0x8F00FF

# define DEFAULT_COLOR 0xFFFFFF
// Colours for the different elevation zones.
// 1 is the lowest and 5 is the highest.
# define ZONE_1 0xFF0000
# define ZONE_2 0xFFFF00
# define ZONE_3 0x00FFFF
# define ZONE_4 0x0000FF
# define ZONE_5 0xFF00FF

// Error message macros
# define ARG_ERR "Usage: './fdf file.fdf'."
# define FDF_INIT_ERR "Error: An error occurred while initialising \
	the fdf struct."
# define FILE_NAME_ERR "Error: File should end with '.fdf' extension."
# define FILE_OPEN_ERR "Error: File could not be opened."
# define MAP_INIT_ERR "Error: An error occurred while initialising \
	the map struct."
# define MALLOC_ERR "Error: Memory allocation failure"
# define VIEW_INIT_ERR "Error: An error occurred while initialising \
	the view struct."

// Structs initialisation functions
t_map	*map_init(void);
t_view	*view_init(t_map *map);
t_fdf	*fdf_init(t_map *map, t_view *view);

// Error handling functions
void	err_and_exit(char *err_msg);
void	free_map_and_exit(t_map *map, char *err_msg);
void	free_fdf_and_exit(t_fdf *fdf, char *err_msg);
void	free_double_arr(char **arr);

// Map parsing functions
void	parse_map(char **av, t_map *map);
bool	check_file_extension(const char *filename);
void	malloc_arrays(char **av, t_map *map);
void	parse_line(char *line, t_map *map, int *index);
void	extract_z_and_color(char *coord_data,
			int *z_arr, int *color_arr, int index);
void	update_elevation_colors(t_map *map, int index);

// Map parsing util functions
void	set_map_height(char **av, t_map *map);
void	set_map_width(char **av, t_map *map);
void	count_columns(char *line, int *column_count);
int		ft_atoi_base(const char *str, int str_base);
void	set_z_range(t_map *map, int index);

// Color functions
int		get_gradient_color(t_point current, t_point start, t_point end,
			t_point delta);
double	get_relative_position(int current, int start, int end);
int		modify_color_component(int start, int end, double relative_position);
int		get_elevation_color(int z, t_map *map);

// Bresenham line drawing algorithm functions
void	draw_line(t_point start, t_point end, t_fdf *fdf);
void	set_delta(t_point start, t_point end, t_point *delta);
void	set_step(t_point start, t_point end, t_point *sign);
void	put_pixel_on_img(int x, int y, int color, t_fdf *fdf);

// Drawing functions
void	draw(t_map *map, t_fdf *fdf);
void	clear_image(t_fdf *fdf);
void	print_panel(t_fdf *fdf);
t_point	create_point(int x, int y, t_map *map);
int		get_index(int x, int y, int width);

// Hook functions
void	setup_hooks(t_fdf *fdf);
int		key_press(int key, t_fdf *fdf);
int		close_window(t_fdf *fdf);

// View modifying functions
void	zoom(int key, t_fdf *fdf);
void	move(int key, t_fdf *fdf);
void	rotate(int key, t_fdf *fdf);
void	change_projection(int key, t_fdf *fdf);
void	change_parallel_view(t_fdf *fdf);

// Projection functions
t_point	project_point(t_point p, t_fdf *fdf);
void	convert_to_isometric(int *x, int *y, int z);
void	rotate_x(int *y, int *z, double alpha);
void	rotate_y(int *x, int *z, double beta);
void	rotate_z(int *x, int *y, double gamma);

#endif
