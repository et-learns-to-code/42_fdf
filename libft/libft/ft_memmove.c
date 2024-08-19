/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:57 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:21:46 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Moves memory, handles overlapping.
void	*ft_memmove(void	*dst, const void	*src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (dst);
	if (dst == src)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d > s)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		while (len--)
			*d++ = *s++;
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    // Test case 1: Non-overlapping regions
    char dest1[20] = "Hello, World!";
    const char *src1 = "OpenAI";
    printf("Before ft_memmove (non-overlapping): %s\n", dest1);
    ft_memmove(dest1, src1, strlen(src1) + 1);
    printf("After ft_memmove (non-overlapping): %s\n\n", dest1);

    // Test case 2: Overlapping regions, dst after src
    char dest2[20] = "Hello, World!";
    printf("Before ft_memmove (overlapping, dst after src): %s\n", dest2);
    ft_memmove(dest2 + 6, dest2, strlen(dest2) + 1);
    printf("After ft_memmove (overlapping, dst after src): %s\n\n", dest2);

    // Test case 3: Overlapping regions, src after dst
    char dest3[20] = "Hello, World!";
    printf("Before ft_memmove (overlapping, src after dst): %s\n", dest3);
    ft_memmove(dest3, dest3 + 6, strlen(dest3) - 5);
    printf("After ft_memmove (overlapping, src after dst): %s\n\n", dest3);

    // Test case 4: src and dst are the same
    char dest4[20] = "Hello, World!";
    printf("Before ft_memmove (src and dst are the same): %s\n", dest4);
    ft_memmove(dest4, dest4, strlen(dest4) + 1);
    printf("After ft_memmove (src and dst are the same): %s\n\n", dest4);

    // Test case 5: src or dst is NULL
    char dest5[20] = "Hello, World!";
    printf("Before ft_memmove (src is NULL): %s\n", dest5);
    ft_memmove(dest5, NULL, 5);
    printf("After ft_memmove (src is NULL): %s\n\n", dest5);

    char *src5 = "Hello";
    printf("Before ft_memmove (dst is NULL): %s\n", src5);
    ft_memmove(NULL, src5, 5);
    printf("After ft_memmove (dst is NULL): %s\n\n", src5);

    return 0;
}
*/
