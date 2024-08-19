/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:59:25 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:20:07 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns length of string.
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    const char *test_strings[] = {"Hello", "World", "", "1234567890",
	"This is a test string"};
    int num_test_strings = sizeof(test_strings) / sizeof(test_strings[0]);

    printf("Testing ft_strlen function:\n");
    for (int i = 0; i < num_test_strings; i++) {
        printf("ft_strlen(\"%s\") = %lu\n", test_strings[i],
		ft_strlen(test_strings[i]));
    }

    printf("\nTesting strlen function from manual:\n");
    for (int i = 0; i < num_test_strings; i++) {
        printf("strlen(\"%s\") = %lu\n", test_strings[i],
		strlen(test_strings[i]));
    }

    return 0;
}
*/
