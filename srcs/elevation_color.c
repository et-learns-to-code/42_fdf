/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elevation_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:30:59 by etien             #+#    #+#             */
/*   Updated: 2024/08/26 18:53:44 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// This function handles for two scenarios:
// 1) At least one color was specified
// - In this case, all unspecified colors will be set to the default color.
// 2) No colors were specified
// - All coordinates will be assigned their elevation color based
//   on their respective z-values.
void	update_elevation_colors(t_map *map, int index)
{
	bool	elevation_colors;
	int		i;
	int		z;

	if (index <= 0 || map->color_arr == NULL)
		return ;
	elevation_colors = true;
	check_specified_colors(map, index, &elevation_colors);
	i = 0;
	while (i < index)
	{
		if (elevation_colors)
		{
			z = map->z_arr[i];
			map->color_arr[i] = get_elevation_color(z, map);
		}
		else
		{
			if (map->color_arr[i] < 0)
				map->color_arr[i] = DEFAULT_COLOR;
		}
		i++;
	}
}

// This function will check for specified colors by iterating through
// the color_arr and checking for color values greater than 0.
// It will set the elevation colors boolean to false if there are
// specified colors.
void	check_specified_colors(t_map *map, int index, bool *elevation_colors)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (map->color_arr[i] > 0)
		{
			*elevation_colors = false;
			break ;
		}
		i++;
	}
}

// This function will return the correct elevation colour for
// a given z value by calculating its percentage elevation.
// The z_range will be segmented into five elevation zones,
// each with their own unique colors. This will make the
// difference in elevation across the map immediately clear
// through distinct colors.
// The default color will be returned in edge cases
// e.g. when range = 0.
// Early return is necessary to avoid division by zero.
// Multiplying 100 before division can preserve the numerical precision
// otherwise lost from integer division.
int	get_elevation_color(int z, t_map *map)
{
	int	percent_elevation;

	if (map->z_range == 0)
		return (DEFAULT_COLOR);
	percent_elevation = (z - map->z_min) * 100 / map->z_range;
	if (percent_elevation >= 0 && percent_elevation <= 20)
		return (ZONE_1);
	else if (percent_elevation > 20 && percent_elevation <= 40)
		return (ZONE_2);
	else if (percent_elevation > 40 && percent_elevation <= 60)
		return (ZONE_3);
	else if (percent_elevation > 60 && percent_elevation <= 80)
		return (ZONE_4);
	else if (percent_elevation > 80 && percent_elevation <= 100)
		return (ZONE_5);
	else
		return (DEFAULT_COLOR);
}
