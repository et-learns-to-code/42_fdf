/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:13:10 by etien             #+#    #+#             */
/*   Updated: 2025/03/15 11:01:50 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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

// This function will run through all the lines in the map
// and set the width based on the line with the most columns.
// This info is necessary because some lines may have more columns
// than others and we have to pad the shorter lines so that the
// map can render without issues.
void	set_map_width(t_map *map, t_list *lst)
{
	int		column_count;
	int		width;

	while (lst)
	{
		column_count = 0;
		count_columns(lst->content, &column_count);
		if (column_count > width)
			width = column_count;
		lst = lst->next;
	}
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

// This function will set the z_range in the map struct.
// z_min and z_max are initialized to the first value of arr.z.
// Their values will be updated from subsequent comparisons.
// Since arr is an integer array, the safe way to iterate
// through the array is to use the array size to terminate
// the while loop. The array size will be available from the
// previously used index variable.
void	set_z_range(t_map *map, int index)
{
	int	z_min;
	int	z_max;
	int	z_range;
	int	i;

	if (index <= 0 || map->arr == NULL)
		return ;
	z_min = map->arr[0].z;
	z_max = map->arr[0].z;
	i = 1;
	while (i < index)
	{
		if (map->arr[i].z < z_min)
			z_min = map->arr[i].z;
		if (map->arr[i].z > z_max)
			z_max = map->arr[i].z;
		i++;
	}
	z_range = z_max - z_min;
	if (z_range < 0)
		z_range = -z_range;
	map->z_min = z_min;
	map->z_max = z_max;
	map->z_range = z_range;
}
