/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:49:03 by etien             #+#    #+#             */
/*   Updated: 2025/03/15 10:55:43 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// This function will parse the line returned from get_next_line.
// First, it will replace the newline character at the end of the
// line with a null terminator. This will ensure that the newline
// character is not incorrectly saved to the array.
void	parse_line(char *line, t_map *map, int *index)
{
	int		len;
	int		i;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	i = 0;
	parse_data(line, map, index, &i);
	pad_map(map, index, i);
}

// This function will add a null terminator to the end of each data 
// coordinate before it is extracted into the arr by extract_z_and_color.
// The workflow for every line is as follows:
// 1) skip over whitespace characters.
// 2) if null terminator reached, break out of the loop.
// 3) skip over non-whitespace characters.
// 4) null terminate the data coordinate.
// 5) null-terminated data coordinate is passed to extract_z_and_color.
void	parse_data(char *line, t_map *map, int *index, int *i)
{
	char	*eol;
	char	*data;

	eol = line + ft_strlen(line);
	data = line;
	while (*line)
	{
		while (line < eol && ft_strchr(WHITESPACE, *line))
			line++;
		if (!*line)
			break ;
		data = line;
		while (line < eol && !ft_strchr(WHITESPACE, *line))
			line++;
		if (*line)
		{
			*line = '\0';
			line++;
		}
		extract_z_and_color(data, map->arr, *index);
		(*index)++;
		(*i)++;
	}
}

// This function will extract the z and hexadecimal color values
// from the coordinate's data to the arr.
// Visualization of data format:
// 		Data: nbr\0
// 		Data with color: nbr,color\0
//		--> processed to nbr\0color\0
// The z and color values are each passed to ft_atoi_base to get 
// their integer representations.
// If a coordinate data does not have a color value, it will be assigned
// -1 by default.
void	extract_z_and_color(char *data, t_arr *arr, int index)
{
	int		i;
	char	*nbr;

	i = 0;
	nbr = data;
	while (data[i] == '-' || ft_isdigit(data[i]))
		i++;
	if (data[i] == ',')
	{
		data[i] = '\0';
		arr[index].z = ft_atoi_base(nbr, 10);
		i++;
		arr[index].color = ft_atoi_base(data + i, 16);
		return ;
	}
	arr[index].z = ft_atoi_base(nbr, 10);
	arr[index].color = -1;
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

// If there are fewer coordinates in a line than the map width,
// this function will pad the arrays and set up default
// values as placeholders with z = 0 and color = -1.
void	pad_map(t_map *map, int *index, int i)
{
	while (i < map->width)
	{
		map->arr[*index].z = 0;
		map->arr[*index].color = -1;
		(*index)++;
		i++;
	}
}
