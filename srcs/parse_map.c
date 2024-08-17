/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:04:59 by etien             #+#    #+#             */
/*   Updated: 2024/08/17 11:43:41 by etien            ###   ########.fr       */
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
// If the line is shorter than the map width, the line will be padded
// with extra 0's (z = 0; color is not set).
// The line is split to separate the data for each coordinate then
// the extract function parses and stores the individual z and color
// data into their correct arrays.
// The logic for freeing is to free as soon as the data is no longer
// needed (see freeing for temp, line and splitted line).
void	parse_line(char *line, t_map *map, int *index)
{
	int		column_count;
	char	*temp;
	char	**splitted_line;
	int		i;

	column_count = 0;
	count_columns(line, &column_count);
	while (column_count < map->width)
	{
		temp = line;
		line = ft_strjoin(temp, " 0 ");
		free(temp);
		column_count++;
	}
	splitted_line = ft_split(line, ' ');
	free(line);
	i = 0;
	while (splitted_line[i])
	{
		extract_z_and_color(splitted_line[i], map->z_arr, map->color_arr,
			*index);
		(*index)++;
		i++;
	}
	free_double_arr(splitted_line);
}

// This function will extract the z and hexadecimal color value
// from the raw data for each coordinate to their correct arrays.
void	extract_z_and_color(char *raw_data, int *z_arr, int *color_arr,
			int index)
{
	char	*nbr;
	char	*hex;
	int		i;
	int		nbr_len;

	i = 0;
	nbr_len = 0;
	while (raw_data[i] == '-' || ft_isdigit(raw_data[i]))
	{
		nbr_len++;
		i++;
	}
	nbr = ft_substr(raw_data, 0, nbr_len);
	z_arr[index] = ft_atoi_base(nbr, 10);
	free(nbr);
	if (raw_data[i] == ',')
	{
		hex = ft_substr(raw_data, i + 1,
				ft_strlen(raw_data) - (i + 1));
		color_arr[index] = ft_atoi_base(hex, 16);
		free(hex);
	}
	else
		color_arr[index] = DEFAULT_COLOR;
}
