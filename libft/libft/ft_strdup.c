/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:57:34 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:25:31 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Duplicates string.
char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s1) + 1;
	dst = (char *)malloc(len);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, len);
	return (dst);
}

/*
#include <stdio.h>

int main() {
    const char *str = "Hello, world!";
    char *duplicate = ft_strdup(str);

    if (duplicate) {
        printf("Original string: %s\n", str);
        printf("Duplicate string: %s\n", duplicate);
        free(duplicate); // Free the memory allocated by ft_strdup
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
*/
