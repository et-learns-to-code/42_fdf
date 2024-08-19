/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:26:48 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:25:21 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// if (count && size && count > UINT_MAX / size) checks if
// the multiplication of count and size would overflow the maximum value
// representable by an unsigned integer. If it would, the function returns NULL
// to indicate failure.

// (count * size) > UINT_MAX seems intuitive, but it can cause undefined
// behavior due to integer overflow before the comparison even happens.
// To avoid this, you need to check for overflow without performing
// the multiplication directly.

// Standard library functions like malloc typically operate within the
// addressable memory space, which is often constrained by the limits
// of unsigned int. Using UINT_MAX ensures that the allocation request
// stays within the practical limits of what the system can handle,
// making it a safer bound for checking overflows in many contexts.

// size_t is an unsigned type, negative values for count and size passed
// as arguments would be implicitly converted to large positive values,
// which the overflow check will catch.

// malloc(0) typically returns a unique pointer that can be freed later

// Allocates and zeros memory.
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count != 0 && size != 0 && count > UINT_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

/*
#include <stdio.h>

int main() {
    int *arr;
    size_t count = 5;

    // Using ft_calloc to allocate and zero-initialize an array of 5 integers
    arr = (int *)ft_calloc(count, sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Printing the allocated array to check if it's zero-initialized
    for (size_t i = 0; i < count; i++) {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }

    // Free the allocated memory
    free(arr);
    return 0;
}
*/
