/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_macos.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:10:28 by etien             #+#    #+#             */
/*   Updated: 2024/08/19 23:04:10 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_MACOS_H
# define KEYCODE_MACOS_H

// Key masks
// macOS uses the Quartz event system for handling input events.
// Event masks can be represented simply by integer values like 0.
# define KEY_PRESS_MASK 0

// Event hooks
# define ON_KEYDOWN 2
# define ON_DESTROY 17

// Exit key
# define ESC_KEY 53

// Zoom keys
# define PLUS_KEY 24
# define MINUS_KEY 27

// Translation/movement keys
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2

// Rotation keys
# define NUM_1_KEY 18
# define NUM_2_KEY 19
# define NUM_3_KEY 20
# define NUM_7_KEY 26
# define NUM_8_KEY 28
# define NUM_9_KEY 25

// Change projection key
# define I_KEY 34
# define P_KEY 35

#endif
