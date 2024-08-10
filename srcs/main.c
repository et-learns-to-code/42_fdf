/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:26:44 by etien             #+#    #+#             */
/*   Updated: 2024/08/10 16:34:26 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_exit(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

int	handle_key(int keycode, t_fdf *fdf)
{
	if (keycode == ESC_KEY)
		free_exit(fdf);
	ft_printf("keycode %d\n", keycode);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac == 2)
	{
		if (check_file_extension(av[1]))
			ft_printf("good file name\n");
		else
			err_and_exit(FILENAME_ERR);
		fdf = init_fdf();

		draw_line(a, b, &fdf);
		mlx_key_hook(fdf.win, &handle_key, &fdf);
		mlx_loop(fdf.mlx);
	}
	else
		err_and_exit(ARG_ERR);
	return (0);
}
