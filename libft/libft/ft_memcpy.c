/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:58:40 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:21:23 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies memory.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    char dest[20] = "Hello, World!";
    const char *src = "OpenAI";

    printf("Before ft_memcpy: %s\n", dest);

    // Call your ft_memcpy function
    ft_memcpy(dest + 7, src, strlen(src) + 1);

    printf("After ft_memcpy: %s\n", dest);

    return 0;
}
*/
