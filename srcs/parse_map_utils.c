/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:13:10 by etien             #+#    #+#             */
/*   Updated: 2024/08/19 14:34:46 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// This function will count the number of lines in the file
// to set the height of the map.
// Read permissions are sufficient because we are not
// modifying the file, only reading it to count the lines.
void	set_map_height(char **av, t_map *map)
{
	int		height;
	int		fd;
	char	*line;

	height = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		free_map_and_exit(map, FILE_OPEN_ERR);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->height = height;
}

// This function will run through all the lines in the map
// and set the width based on the line with the most columns.
// This info is necessary because some lines may have more columns
// than others and we have to pad the shorter lines so that the
// map can render without issues.
void	set_map_width(char **av, t_map *map)
{
	int		width;
	int		fd;
	char	*line;
	int		column_count;

	width = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		free_map_and_exit(map, FILE_OPEN_ERR);
	line = get_next_line(fd);
	while (line)
	{
		column_count = 0;
		count_columns(line, &column_count);
		if (column_count > width)
			width = column_count;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->width = width;
}

// This function will count the number of columns in the line fetched by
// the get_next_line function.
// The while loop for line[i] identifies and counts the start of each new
// column in the line by checking where non-space characters are preceded
// by a space or are at the beginning of the line.
// Order of (i == 0 || line[i - 1] == ' ') is crucial because of OR's
// short-circuit evaluation which will prevent segmentation fault from
// evaluation of the second statement if i is 0 (at the start of the line).
void	count_columns(char *line, int *column_count)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && (i == 0 || line[i - 1] == ' '))
			(*column_count)++;
		i++;
	}
}

// This function will convert the given string to its decimal integer value
// based on the specified base.
// The if condition for base 16 will move the string pointer two spaces
// to move past its '0x' prefix.
int	ft_atoi_base(const char *str, int str_base)
{
	int	sign;
	int	result;
	int	decimal_value;

	sign = 1;
	result = 0;
	decimal_value = 0;
	if (str_base == 16)
		str += 2;
	while (*str && str_base <= 16)
	{
		if (*str == '-')
			sign *= -1;
		else if (*str >= '0' && *str <= '9')
			decimal_value = *str - '0';
		else if (*str >= 'A' && *str <= 'F')
			decimal_value = *str - 'A' + 10;
		else if (*str >= 'a' && *str <= 'f')
			decimal_value = *str - 'a' + 10;
		else
			break ;
		result = result * str_base + decimal_value;
		str++;
	}
	return (sign * result);
}

// This function will set the z_range in the map struct.
// z_min and z_max are initialized to the first value in the z_arr.
// Their values will be updated from subsequent comparisons.
// Since z_arr is an integer array, the safe way to iterate
// through the array is to use the array size to terminate
// the while loop. The array size will be available from the
// previously used index variable.
void	set_z_range(t_map *map, int index)
{
	int	z_min;
	int	z_max;
	int	z_range;
	int	i;

	if (index <= 0 || map->z_arr == NULL)
		return ;
	z_min = map->z_arr[0];
	z_max = map->z_arr[0];
	i = 1;
	while (i < index)
	{
		if (map->z_arr[i] < z_min)
			z_min = map->z_arr[i];
		if (map->z_arr[i] > z_max)
			z_max = map->z_arr[i];
		i++;
	}
	z_range = z_max - z_min;
	if (z_range < 0)
		z_range = -z_range;
	map->z_range = z_range;
}
