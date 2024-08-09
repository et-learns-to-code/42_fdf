/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:27:16 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:25:52 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Extracts substring from string.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s) - 1)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}

/*
#include <stdio.h>

int main(void) {
    const char *str = "Bonjour comment ca va?";
    unsigned int start = 5;
    size_t len = 8;
    char *result = ft_substr(str, start, len);

    if (result) {
        printf("Substring: '%s'\n", result);
        free(result);
    } else {
        printf("Failed to allocate memory for substring.\n");
    }

    return 0;
}
*/
