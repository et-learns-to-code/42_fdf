/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:13:51 by etien             #+#    #+#             */
/*   Updated: 2025/03/18 10:34:31 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// This function uses hooks to register callback functions that will intercept
// certain events, such as pressing of certain keys or closing of the window.
// ON_DESTROY event corresponds to user clicking the close button on the
// window's title bar.
// mlx_hook function only permits one parameter, which is the reason we
// created the gigantic fdf struct, so that we could easily transport
// all necessary variables in one parameter.
// Mask parameter in mlx_hook function is for more granular control
// over event handling than what is set within the event parameter.
// mlx_loop_hook makes render_frame run continuously in the background 
// (instead of only when an event occurs).
void	setup_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, ON_KEYDOWN, KEY_PRESS_MASK, key_press, fdf);
	mlx_hook(fdf->win, ON_KEYUP, KEY_RELEASE_MASK, key_release, fdf);
	mlx_hook(fdf->win, ON_DESTROY, KEY_PRESS_MASK, close_window, fdf);
	mlx_loop_hook(fdf->mlx, render_frame, fdf);
}

// Pressing the key will toggle its value to 1 in the keys array.
int	key_press(int key, t_fdf *fdf)
{
	if (key == ESC_KEY)
		free_fdf_and_exit(fdf, NULL);
	else if (key == I_KEY || key == P_KEY)
		change_projection(key, fdf);
	if (key < TOTAL_KEYS)
		fdf->view.keys[key] = 1;
	return (0);
}

//	Releasing the key will toggle its value to 0 in the keys array.
int	key_release(int key, t_fdf *fdf)
{
	if (key < TOTAL_KEYS)
		fdf->view.keys[key] = 0;
	return (0);
}

// This function will check if any keys are pressed and will update the view.
// The function runs in mlx_loop_hook, which means it will run continuously,
// so update_view is used to prevent unnecessary rendering of the same frame.
int	render_frame(t_fdf *fdf)
{
	int	*keys;
	int	update_view;

	keys = fdf->view.keys;
	update_view = 0;
	if (keys[PLUS_KEY] || keys[MINUS_KEY])
		zoom(keys, fdf, &update_view);
	if (keys[W_KEY] || keys[S_KEY]
		|| keys[A_KEY] || keys[D_KEY])
		move(keys, fdf, &update_view);
	if (keys[NUM_1_KEY] || keys[NUM_2_KEY]
		|| keys[NUM_3_KEY] || keys[NUM_7_KEY]
		|| keys[NUM_8_KEY] || keys[NUM_9_KEY])
		rotate(keys, fdf, &update_view);
	if (keys[SPACE_BAR])
		invert_colors(keys, fdf, &update_view);
	if (update_view)
		draw(&fdf->map, fdf);
	return (0);
}

// This function is also connected to the mlx hook and will clean up resources
// and exit with status 0 (because of NULL parameter) when the window is closed.
int	close_window(t_fdf *fdf)
{
	free_fdf_and_exit(fdf, NULL);
	return (0);
}
