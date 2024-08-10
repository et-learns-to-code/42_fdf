/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:13:51 by etien             #+#    #+#             */
/*   Updated: 2024/08/10 19:05:37 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	setup_controls()
{

}

// This function will be connected to the mlx hook, so
// that the relevant view function will be called when its
// associated key is pressed.
int key_press(int key, t_fdf *fdf)
{
	if (key == ESC_KEY)
		exit(0);
	if (key == P_KEY)
		change_projection(key, fdf);
	else if (key == PLUS_KEY || key == MINUS_KEY)
		zoom(key, fdf);
	else if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
		move(key, fdf);
	else if (key == NUM_1_KEY || key == NUM_2_KEY
		|| key == NUM_3_KEY || key == NUM_4_KEY
		|| key == NUM_5_KEY || key == NUM_6_KEY)
		rotate(key, fdf);
	return (0);
}
