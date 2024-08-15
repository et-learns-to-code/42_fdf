/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:13:10 by etien             #+#    #+#             */
/*   Updated: 2024/08/15 17:34:00 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

// This function will count the number of lines in the file
// to determine the height of the map.
// Read permissions are sufficient because we are not
// modifying the file, only reading it to count the lines.
void	get_map_height(char **av, t_map *map)
{
	int		height;
	int		fd;
	char	*line;

	height = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		err_and_exit(FILE_OPEN_ERR);
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
void	get_map_width(char **av, t_map *map)
{
	int		width;
	int		fd;
	char	*line;
	int		column_count;

	width = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		err_and_exit(FILE_OPEN_ERR);
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

// int main(int ac, char **av)
// {
// 	int		fd;
// 	int		height;
// 	char	*line;
// 	t_map *map = NULL;
// 	int z_arr[10];
// 	int color_arr[10];

// 	(void) ac;
// 	height = 0;

// 	fd = open(av[1], O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		parse_line(line, map);
// 		height++;
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	ft_printf("Height: %d\n", height);
// 	ft_printf("%d\n", ft_atoi_base("0xFFFF", 16));
// 	ft_printf("%d\n", ft_atoi_base("12345435", 10));
// 	extract_z_and_color("20,0xFF0000", z_arr, color_arr, 1);
// 	ft_printf("Z: %d\n", z_arr[1]);
// 	ft_printf("Color: %d\n", color_arr[1]);
// 	close(fd);
// 	return (0);
// }

// This function will parse the line returned from get_next_line.
// If the line is shorter than the map width, the line will be padded
// with extra 0's (z = 0; color is not set).
// The line is split to separate the data for each coordinate then
// the extract function parses and stores the z and color data into their
// correct arrays.
void	parse_line(char *line, t_map *map, int *index)
{
	int		column_count;
	char	*temp;
	char	**splitted_line;
	int		i;

	count_columns(line, column_count);
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
