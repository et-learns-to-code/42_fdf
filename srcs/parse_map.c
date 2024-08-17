/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:04:59 by etien             #+#    #+#             */
/*   Updated: 2024/08/17 15:12:12 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// This function will parse the map and set up all the data
// in the map struct.
// It will first check that the file extension is correct,
// otherwise the program will free the map struct and exit.
// Map width and height will be set in the malloc_arrays function
// and the function will also allocate memory for the z and color arrays.
// The program will open the file and call parse_line in a while loop
// to parse and fill the arrays.
// Finally, the file descriptor is closed once the parsing is complete.
void parse_map(char **av, t_map *map)
{
	int		fd;
	char	*line;
	int		index;

	if (!check_file_extension(av[1]))
		free_map_and_exit(map, FILE_NAME_ERR);
	malloc_arrays(av, map);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		free_map_and_exit(map, FILE_OPEN_ERR);
	index = 0;
	line = get_next_line(fd);
	while (line)
	{
		parse_line(line, map, &index);
		line = get_next_line(fd);
	}
	close(fd);
}

// This function allocates the memory for the z and color arrays
// after determining the width and height of the map.
// It also handles for error in case memory fails to be allocated
// for the arrays.
void	malloc_arrays(char **av, t_map *map)
{
	get_map_height(av, map);
	get_map_width(av, map);
	map->z_arr = malloc((map->height * map->width) * sizeof(int));
	if (!map->z_arr)
		free_map_and_exit(map, MALLOC_ERR);
	map->color_arr = malloc((map->height * map->width) * sizeof(int));
	if (!map->color_arr)
		free_map_and_exit(map, MALLOC_ERR);
}

// This function will parse the line returned from get_next_line.
// First, it will replace the newline character at the end of the
// line with a null terminator. This will ensure that the newline
// character is not incorrectly saved to the array when the line
// is split.
// The line is split to separate the data for each coordinate
// then the extract function parses and stores the z and color
// data into their correct arrays.
// If there are fewer coordinates in a line than the map width,
// the second while loop will pad the arrays and set up default
// values as placeholders with z = 0 and color = DEFAULT_COLOR.
// Allocated memory is always freed as soon as the data is
// no longer needed (see freeing for line and coord data).
void	parse_line(char *line, t_map *map, int *index)
{
	int		line_length;
	char	**coord_data;
	int		i;

	line_length = ft_strlen(line);
	if (line_length > 0 && line[line_length - 1] == '\n')
		line[line_length - 1] = '\0';
	coord_data = ft_split(line, ' ');
	free(line);
	i = 0;
	while (coord_data[i] && i < map->width)
	{
		extract_z_and_color(coord_data[i], map->z_arr, map->color_arr,
			*index);
		(*index)++;
		i++;
	}
	while (i < map->width)
	{
		map->z_arr[*index] = 0;
		map->color_arr[*index] = DEFAULT_COLOR;
		(*index)++;
		i++;
	}
	free_double_arr(coord_data);
}

// This function will extract the z and hexadecimal color value
// from the coordinate's data to their correct arrays.
void	extract_z_and_color(char *coord_data, int *z_arr, int *color_arr,
			int index)
{
	char	*nbr;
	char	*hex;
	int		i;
	int		nbr_len;

	i = 0;
	nbr_len = 0;
	while (coord_data[i] == '-' || ft_isdigit(coord_data[i]))
	{
		nbr_len++;
		i++;
	}
	nbr = ft_substr(coord_data, 0, nbr_len);
	z_arr[index] = ft_atoi_base(nbr, 10);
	free(nbr);
	if (coord_data[i] == ',')
	{
		hex = ft_substr(coord_data, i + 1,
				ft_strlen(coord_data) - (i + 1));
		color_arr[index] = ft_atoi_base(hex, 16);
		free(hex);
	}
	else
		color_arr[index] = DEFAULT_COLOR;
}
