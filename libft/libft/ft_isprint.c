/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:24:35 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:19:42 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Checks if character is printable.
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*
#include <stdio.h>
#include <ctype.h>

int main() {
    char test_chars[] = {'A', 'b', '3', '$', ' ', '~', '\t'};
    int num_test_chars = sizeof(test_chars) / sizeof(test_chars[0]);

    printf("Testing ft_isprint function:\n");
    for (int i = 0; i < num_test_chars; i++) {
        printf("ft_isprint('%c') = %d\n", test_chars[i],
		ft_isprint(test_chars[i]));
    }

    printf("\nTesting isprint function from manual:\n");
    for (int i = 0; i < num_test_chars; i++) {
        printf("isprint('%c') = %d\n", test_chars[i],
		isprint(test_chars[i]));
    }

    return 0;
}
*/
