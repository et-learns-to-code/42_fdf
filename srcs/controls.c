/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:13:51 by etien             #+#    #+#             */
/*   Updated: 2024/08/22 13:21:07 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// This function uses hooks to register callback functions that will intercept
// certain events, such as pressing of certain keys or closing of the window.
// ON_DESTROY event corresponds to user clicking the close button on the
// window's title bar.
// mlx_hook function only permits one parameter, which is the reason we
// created the gigantic fdf struct, so that we could easily transport
// all necessary variables in one parameter.
// Mask parameter in mlx_hook function is for more granular control
// over event handling than what is set within the event parameter.
// However, for this project, we will set it to 0 and not bother with it.
void	setup_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, ON_KEYDOWN, KEY_PRESS_MASK, key_press, fdf);
	mlx_hook(fdf->win, ON_DESTROY, KEY_PRESS_MASK, close_window, fdf);
}

// This function is connected to the mlx hook and will call the relevant
// view function when its associated key is pressed.
int	key_press(int key, t_fdf *fdf)
{
	if (key == ESC_KEY)
		free_fdf_and_exit(fdf, NULL);
	else if (key == PLUS_KEY || key == MINUS_KEY)
		zoom(key, fdf);
	else if (key == UP_KEY || key == DOWN_KEY
		|| key == LEFT_KEY || key == RIGHT_KEY
		|| key == W_KEY || key == S_KEY
		|| key == A_KEY || key == D_KEY)
		move(key, fdf);
	else if (key == NUM_1_KEY || key == NUM_2_KEY
		|| key == NUM_3_KEY || key == NUM_7_KEY
		|| key == NUM_8_KEY || key == NUM_9_KEY)
		rotate(key, fdf);
	else if (key == I_KEY || key == P_KEY)
		change_projection(key, fdf);
	else if (key == SPACE_BAR)
		invert_colors(key, fdf);
	return (0);
}

// This function is also connected to the mlx hook and will clean up resources
// and exit with status 0 (because of NULL parameter) when the window is closed.
int	close_window(t_fdf *fdf)
{
	free_fdf_and_exit(fdf, NULL);
	return (0);
}
