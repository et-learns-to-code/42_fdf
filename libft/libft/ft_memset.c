/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:55:55 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:20:29 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Sets memory to a value.
void	*ft_memset(void	*b, int c, size_t len)
{
	unsigned char	*a;

	a = (unsigned char *)b;
	while (len--)
	{
		*a++ = (unsigned char)c;
	}
	return (b);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];

    // Use the custom memset function
    ft_memset(buffer, 'A', sizeof(buffer));

    // Print the buffer to verify it was correctly set
    for (size_t i = 0; i < sizeof(buffer); i++) {
        printf("%c ", buffer[i]);
    }
    printf("\n");

    return 0;
}
*/
