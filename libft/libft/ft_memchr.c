/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:35:18 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:24:11 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Finds first occurrence of byte.
void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
		n--;
	}
	return (NULL);
}

/*
#include <stdio.h>

int main() {
    char str[] = "Hello, world!";
    char *ptr1, *ptr2;

    // Testing ft_memchr function
    ptr1 = ft_memchr(str, 'o', strlen(str));
    if (ptr1 != NULL)
        printf("ft_memchr found 'o' at position: %ld\n", ptr1 - str);
    else
        printf("ft_memchr did not find 'o'\n");

    // Testing memchr function
    ptr2 = memchr(str, 'o', strlen(str));
    if (ptr2 != NULL)
        printf("memchr found 'o' at position: %ld\n", ptr2 - str);
    else
        printf("memchr did not find 'o'\n");

    return 0;
}
*/
