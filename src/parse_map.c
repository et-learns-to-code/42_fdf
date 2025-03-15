/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:04:59 by etien             #+#    #+#             */
/*   Updated: 2025/03/15 11:12:19 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// This function will parse the map and set up all the data
// for the map struct. Once the file has been loaded into the 
// temporary linked list and memory has been allocated for the 
// data arr, the function will call parse_line in a while loop to
// fill up the array. 
void	parse_map(char **av, t_map *map, t_fdf *fdf)
{
	t_list	*lst;
	t_list	*tmp;
	int		index;

	lst = load_file_into_tmp(av, fdf);
	malloc_arrays(lst, map, fdf);
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
}

// This function will load the file into a temporary linked list.
// It will first check that the file extension is correct,
// otherwise the program will free the structs and exit.
t_list	*load_file_into_tmp(char **av, t_fdf *fdf)
{
	t_list	*lst;
	int		fd;
	char	*line;

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
	close(fd);
	return (lst);
}

// This function allocates the memory for the z and color array
// after determining the width and height of the map.
// It also handles for error in case memory fails to be allocated
// for the arrays.
void	malloc_arrays(t_list *lst, t_map *map, t_fdf *fdf)
{
	map->height = ft_lstsize(lst);
	set_map_width(map, lst);
	if (map->height == 0 || map->width == 0)
		free_fdf_and_exit(fdf, EMPTY_FILE_ERR);
	map->arr = malloc((map->height * map->width) * sizeof(t_arr));
	if (!map->arr)
		free_fdf_and_exit(fdf, MALLOC_ERR);
}
