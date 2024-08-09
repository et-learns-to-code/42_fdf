/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:56:13 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:28:43 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applies function to each character and creates new array.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}

/*
#include <stdio.h>

// Custom function to be used with ft_strmapi
char my_func(unsigned int i, char c) {
    return c + i % 26;  // Simple transformation for testing:
	// add index to character
}

int main() {
    // Test string
    char test_str[] = "hello";

    // Call ft_strmapi with test string and custom function
    char *result = ft_strmapi(test_str, my_func);

    // Check and print result
    if (result) {
        printf("Original string: %s\n", test_str);
        printf("Transformed string: %s\n", result);
        free(result);  // Free the allocated memory
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
*/
