/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:40:52 by etien             #+#    #+#             */
/*   Updated: 2024/07/18 14:34:08 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Finds last occurrence of character.
char	*ft_strrchr(const char *s, int c)
{
	char	*final;

	final = NULL;
	while (*s)
	{
		if (*s == (char)c)
			final = ((char *)s);
		s++;
	}
	if (*s == (char)c)
		final = ((char *)s);
	return (final);
}

/*
#include <stdio.h>
#include "libft.h"

int main() {
    const char *str = "Hello, world!";
    int target_char = 'o';

    char *result = ft_strrchr(str, target_char);

    if (result != NULL) {
        printf("'%c' found at index: %ld\n", target_char, result - str);
    } else {
        printf("'%c' not found in the string.\n", target_char);
    }

    return 0;
}
*/
