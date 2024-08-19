/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:10:21 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:21:09 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Zeroes memory.
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr++ = 0;
	}
}

/*
#include <stdio.h>
#include <string.h>  // for comparison purposes

int main(void)
{
    // Define an array and initialize it with non-zero values
    char array[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = 'A' + i;  // Fill array with characters 'A' to 'J'
    }

    // Print the original array contents
    printf("Original array: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%c ", array[i]);
    }
    printf("\n");

    // Call ft_bzero to set the array elements to zero
    ft_bzero(array, 10);

    // Print the array contents after calling ft_bzero
    printf("Zeroed array: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);  // Print as integer to show zeroes
    }
    printf("\n");
}
*/
