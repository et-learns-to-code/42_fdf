/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:04:59 by etien             #+#    #+#             */
/*   Updated: 2025/03/14 23:33:14 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// This function will parse the map and set up all the data
// in the map struct.
// It will first check that the file extension is correct,
// otherwise the program will free the map struct and exit.
// Map width and height will be set in the malloc_arrays function
// and the function will also allocate memory for the z and color arrays.
// The program will open the file and call parse_line in a while loop
// to parse and fill the arrays.
// Finally, the file descriptor is closed once the parsing is complete.
void	parse_map(char **av, t_map *map, t_fdf *fdf)
{
	t_list	*lst;
	t_list	*tmp;
	int		fd;
	char	*line;
	int		index;

	if (!check_file_extension(av[1]))
		free_fdf_and_exit(fdf, FILE_NAME_ERR);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		free_fdf_and_exit(fdf, FILE_OPEN_ERR);
	lst = NULL;
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&lst, ft_lstnew(line));
		line = get_next_line(fd);
	}
	map->height = ft_lstsize(lst);
	set_map_width(map, lst);
	malloc_arrays(map, fdf);
	tmp = lst;
	index = 0;
	while (tmp)
	{
		parse_line(tmp->content, map, &index);
		tmp = tmp->next;
	}
	ft_lstclear(&lst, free);
	set_z_range(map, index);
	update_elevation_colors(map, index);
	close(fd);
}

// This function will check that the file inputted as the argument
// ends with the required extension of ".fdf".
// It will check the difference in length in the filename and extension,
// and move the filename's pointer to the position where the extension
// is expected to start.
// If the filename is longer than the extension and the comparison evaluates
// to 0 (i.e. no difference), the function will return true.
// Otherwise, it will return false.
bool	check_file_extension(const char *filename)
{
	const char	*extension = ".fdf";
	size_t		len_filename;
	size_t		len_extension;

	len_filename = ft_strlen(filename);
	len_extension = ft_strlen(extension);
	return (len_filename > len_extension
		&& ft_strncmp(filename + (len_filename - len_extension),
			extension, len_extension) == 0);
}

// This function allocates the memory for the z and color array
// after determining the width and height of the map.
// It also handles for error in case memory fails to be allocated
// for the arrays.
void	malloc_arrays(t_map *map, t_fdf *fdf)
{
	if (map->height == 0 || map->width == 0)
		free_fdf_and_exit(fdf, EMPTY_FILE_ERR);
	map->arr = malloc((map->height * map->width) * sizeof(t_arr));
	if (!map->arr)
		free_fdf_and_exit(fdf, MALLOC_ERR);
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
// values as placeholders with z = 0 and color = -1.
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
	i = 0;
	while (coord_data[i] && i < map->width)
	{
		extract_z_and_color(coord_data[i], map->arr,
			*index);
		(*index)++;
		i++;
	}
	while (i < map->width)
	{
		map->arr[*index].z = 0;
		map->arr[*index].color = -1;
		(*index)++;
		i++;
	}
	free_double_arr(coord_data);
}

// This function will extract the z and hexadecimal color values
// from the coordinate's data to their correct arrays.
// It achieves this by creating substrings of the z and color values
// which are each passed to ft_atoi_base to get their integer
// representations.
// Once the integer values are known and stored into their respective arrays,
// the substrings are freed to avoid memory leakages.
// If a coordinate data does not have a color value, it will be assigned
// -1 by default.
void	extract_z_and_color(char *coord_data, t_arr *arr, int index)
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
	arr[index].z = ft_atoi_base(nbr, 10);
	free(nbr);
	if (coord_data[i] == ',')
	{
		hex = ft_substr(coord_data, i + 1,
				ft_strlen(coord_data) - (i + 1));
		arr[index].color = ft_atoi_base(hex, 16);
		free(hex);
	}
	else
		arr[index].color = -1;
}
