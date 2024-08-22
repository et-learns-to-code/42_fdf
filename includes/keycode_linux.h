/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_linux.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:25:43 by etien             #+#    #+#             */
/*   Updated: 2024/08/22 11:16:49 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_LINUX_H
# define KEYCODE_LINUX_H

// Key masks
// Linux uses X11 so event masks are bitmasks,
// where each bit represents a different type of event.
// 1L<<0 will evaluate to 1.
// We put 1 otherwise norminette will complain that the
// preprocessor statement can only contain a constant.
# define KEY_PRESS_MASK 1

// Event hooks
# define ON_KEYDOWN 2
# define ON_DESTROY 17

// Exit key
# define ESC_KEY 65307

// Zoom keys
# define PLUS_KEY 61
# define MINUS_KEY 45

// Translation/movement keys
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100

// Rotation keys
# define NUM_1_KEY 49
# define NUM_2_KEY 50
# define NUM_3_KEY 51
# define NUM_7_KEY 55
# define NUM_8_KEY 56
# define NUM_9_KEY 57

// Change projection keys
# define I_KEY 105
# define P_KEY 112

// Invert colors key
# define SPACE_BAR 57

#endif
