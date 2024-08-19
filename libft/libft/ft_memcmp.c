/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:00:49 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:24:35 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compares memory areas.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}

/*
#include <stdio.h>

int main() {
    // Test data
    char str1[] = "Hello";
    char str2[] = "Hella";
    size_t n = 5; // Number of bytes to compare

    // Test ft_memcmp
    int result1 = ft_memcmp(str1, str2, n);
    printf("ft_memcmp result: %d\n", result1);

    // Test memcmp
    int result2 = memcmp(str1, str2, n);
    printf("memcmp result: %d\n", result2);

    if (result1 == result2) {
        printf("Results match!\n");
    } else {
        printf("Results differ!\n");
    }

    return 0;
}
*/
