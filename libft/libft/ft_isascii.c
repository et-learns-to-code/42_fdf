/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:46:12 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:19:30 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Checks if character is ASCII.
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*
#include <stdio.h>
#include <ctype.h>

int main() {
    char test_chars[] = {'A', 'b', '3', '$', '\x7F', '\x80'};
    int num_test_chars = sizeof(test_chars) / sizeof(test_chars[0]);

    printf("Testing ft_isascii function:\n");
    for (int i = 0; i < num_test_chars; i++) {
        printf("ft_isascii('%c') = %d\n", test_chars[i],
				ft_isascii(test_chars[i]));
    }

    printf("\nTesting isascii function from manual:\n");
    for (int i = 0; i < num_test_chars; i++) {
        printf("isascii('%c') = %d\n", test_chars[i],
				isascii(test_chars[i]));
    }

    return 0;
}
*/
