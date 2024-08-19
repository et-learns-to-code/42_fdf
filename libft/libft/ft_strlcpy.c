/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:10:43 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:22:01 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies string with size limit.
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize > 0)
	{
		if (src_len + 1 <= dstsize)
			ft_memcpy(dst, src, src_len + 1);
		else
		{
			ft_memcpy(dst, src, dstsize - 1);
			dst[dstsize - 1] = '\0';
		}
	}
	return (src_len);
}

/*
#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
    char dst[20];
    const char *src;
    size_t result;

    // Test case 1: dstsize > src_len + 1
    src = "Hello, World!";
    result = ft_strlcpy(dst, src, sizeof(dst));
    printf("Test 1 - Result: %zu, Dst: %s\n", result, dst);

    // Test case 2: dstsize == src_len + 1
    src = "Hello, World!";
    result = ft_strlcpy(dst, src, 14);
    printf("Test 2 - Result: %zu, Dst: %s\n", result, dst);

    // Test case 3: dstsize < src_len
    src = "Hello, World!";
    result = ft_strlcpy(dst, src, 6);
    printf("Test 3 - Result: %zu, Dst: %s\n", result, dst);

    // Test case 4: Empty source
    src = "";
    result = ft_strlcpy(dst, src, sizeof(dst));
    printf("Test 4 - Result: %zu, Dst: %s\n", result, dst);

    // Test case 5: Zero dstsize
    src = "Hello, World!";
    result = ft_strlcpy(dst, src, 0);
    printf("Test 5 - Result: %zu, Dst: %s\n", result, dst);

    return 0;
}
*/
