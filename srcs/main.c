/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:26:44 by etien             #+#    #+#             */
/*   Updated: 2024/08/16 16:32:18 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_view	*view;
	t_fdf	*fdf;
	t_point	a;
	t_point	b;

	map = NULL;
	if (ac == 2)
	{
		map = map_init();
		parse_map();
		view = view_init();
		fdf = fdf_init(map, view);
		draw(map, fdf);
		setup_hooks(fdf);
		mlx_loop(fdf->mlx);
	}
	else
		err_and_exit(ARG_ERR);
	return (0);
}
