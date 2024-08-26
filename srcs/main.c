/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:26:44 by etien             #+#    #+#             */
/*   Updated: 2024/08/19 16:48:05 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// This is the main function of the fdf program.
// First, it will check that the number of arguments is exactly 2.
// Then, it will initialize the map struct.
// Parse_map will fill the map struct with the correct values,
// before the view and fdf structs are initialized.
// The draw function will produce the first 3D render of the map.
// Then, setup hooks will set up the keyboard controls to make the
// 3D render interactive.
// Finally, mlx_hook will keep the graphics window open and responsive until
// exit conditions are met (e.g. escape key is pressed or 'X' in the
// windows is clicked).
int	main(int ac, char **av)
{
	t_map	*map;
	t_view	*view;
	t_fdf	*fdf;

	if (ac != 2)
		err_and_exit(ARG_ERR);
	map = map_init();
	parse_map(av, map);
	view = view_init(map);
	fdf = fdf_init(map, view, av);
	draw(map, fdf);
	setup_hooks(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
