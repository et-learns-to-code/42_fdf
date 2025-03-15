/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:35:06 by etien             #+#    #+#             */
/*   Updated: 2025/03/15 11:08:49 by etien            ###   ########.fr       */
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

// The relevant keycode header file will be included and width and
// height macros will be defined based on the operating system running.
// __linux__ and __APPLE__ macros are predefined by the compiler.
# ifdef __linux__
#  include "keycode_linux.h"
#  define WIN_WIDTH 1920
#  define WIN_HEIGHT 1080
# elif __APPLE__
#  include "keycode_macos.h"
#  define WIN_WIDTH 1200
#  define WIN_HEIGHT 675
# else
#  error "Unsupported OS"
# endif

// Color macros
# define DEFAULT_COLOR 0xFFFFFF
// Colors for the different elevation zones.
// 1 is the lowest and 5 is the highest.
# define ZONE_1 0xFF0000
# define ZONE_2 0xFFFF00
# define ZONE_3 0x00FFFF
# define ZONE_4 0x0000FF
# define ZONE_5 0xFF00FF

# define ISO_RADIAN  0.52359877559

# define WHITESPACE " \t\r\n\v"

// Error message macros
# define ARG_ERR "Usage: './fdf file.fdf'."
# define EMPTY_FILE_ERR "Error: File was empty."
# define FDF_INIT_ERR \
	"Error: An error occurred while initialising the fdf struct."
# define FILE_NAME_ERR "Error: File should end with '.fdf' extension."
# define FILE_OPEN_ERR "Error: File could not be opened."
# define MAP_INIT_ERR \
	"Error: An error occurred while initialising the map struct."
# define MALLOC_ERR "Error: Memory allocation failure."
# define VIEW_INIT_ERR \
	"Error: An error occurred while initialising the view struct."

// Structs initialisation functions
void	view_init(t_view *view, t_map *map);
void	fdf_init(t_fdf *fdf, char **av);

// Error handling functions
void	err_and_exit(char *err_msg);
void	free_fdf_and_exit(t_fdf *fdf, char *err_msg);

// Map parsing functions
void	parse_map(char **av, t_map *map, t_fdf *fdf);
t_list	*load_file_into_tmp(char **av, t_fdf *fdf);
void	malloc_arrays(t_list *lst, t_map *map, t_fdf *fdf);

// Map parsing util functions
bool	check_file_extension(const char *filename);
void	set_map_width(t_map *map, t_list *lst);
void	count_columns(char *line, int *column_count);
void	set_z_range(t_map *map, int index);

// Map line parsing functions
void	parse_line(char *line, t_map *map, int *index);
void	parse_data(char *line, t_map *map, int *index, int *i);
void	extract_z_and_color(char *coord_data,
			t_arr *arr, int index);
int		ft_atoi_base(const char *str, int str_base);
void	pad_map(t_map *map, int *index, int i);

// Elevation color functions
void	update_elevation_colors(t_map *map, int index);
void	check_specified_colors(t_map *map, int index, bool *elevation_colors);
int		get_elevation_color(int z, t_map *map);

// Gradient color functions
int		get_gradient_color(t_point current, t_point start, t_point end,
			t_point delta);
double	get_relative_position(int current, int start, int end);
int		modify_color_component(int start, int end, double relative_position);

// Bresenham line drawing algorithm functions
void	draw_line(t_point start, t_point end, t_fdf *fdf);
void	set_delta_and_step(t_point start, t_point end, t_point *delta, t_point *step);
void	set_step(t_point start, t_point end, t_point *sign);
void	put_pixel_on_img(int x, int y, int color, t_fdf *fdf);

// Drawing functions
void	draw(t_map *map, t_fdf *fdf);
void	clear_image(t_fdf *fdf);
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
void	convert_to_isometric(int *x, int *y, int z, t_view view);
void	rotate_x(int *y, int *z, double alpha);
void	rotate_y(int *x, int *z, double beta);
void	rotate_z(int *x, int *y, double gamma);

// Color inversion function for bonus
void	invert_colors(int key, t_fdf *fdf);
int		get_inverted_color(int color);

#endif
