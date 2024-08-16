/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:13:10 by etien             #+#    #+#             */
/*   Updated: 2024/08/16 15:05:26 by etien            ###   ########.fr       */
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
