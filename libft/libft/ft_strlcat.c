/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:27:41 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:22:23 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// if (dst_len >= dstsize) handles scenario where destination
// string might not be properly null-terminated

// Concatenates strings with size limit.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	if (src_len < dstsize - dst_len)
		ft_memcpy(dst + dst_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dst_len, src, dstsize - dst_len - 1);
		dst[dstsize - 1] = '\0';
	}
	return (src_len + dst_len);
}

/*
#include <stdio.h>
#include <string.h>

size_t ft_strlcat(char *dst, const char *src, size_t dstsize);

int main() {
    char dst1[20] = "Hello";
    char dst2[20] = "Hello";
    char src[] = ", world!";

    size_t len1 = strlcat(dst1, src, sizeof(dst1));
    size_t len2 = ft_strlcat(dst2, src, sizeof(dst2));

    printf("Original strlcat: Concatenated string: %s,
	Length: %zu\n", dst1, len1);
    printf("Your strlcat:     Concatenated string: %s,
	Length: %zu\n", dst2, len2);

    return 0;
}
*/
