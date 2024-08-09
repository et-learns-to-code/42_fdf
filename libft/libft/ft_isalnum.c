/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:31:24 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:18:12 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Checks if character is alphanumeric.
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
#include <stdio.h>
#include <ctype.h>

int main() {
    char test_chars[] = {'A', 'b', '3', '$', '9'};
    int num_test_chars = sizeof(test_chars) / sizeof(test_chars[0]);

    printf("Testing ft_isalnum function:\n");
    for (int i = 0; i < num_test_chars; i++) {
        printf("ft_isalnum('%c') = %d\n", test_chars[i],
				ft_isalnum(test_chars[i]));
    }

    printf("\nTesting isalnum function from manual:\n");
    for (int i = 0; i < num_test_chars; i++) {
        printf("isalnum('%c') = %d\n", test_chars[i],
				isalnum(test_chars[i]));
    }

    return 0;
}
*/
