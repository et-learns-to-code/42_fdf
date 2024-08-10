/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:13:10 by etien             #+#    #+#             */
/*   Updated: 2024/08/10 17:13:42 by etien            ###   ########.fr       */
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
