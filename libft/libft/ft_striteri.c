/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:22:57 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:29:12 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applies function to each character with index.
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>

// Custom function to be used with ft_striteri
void my_func(unsigned int i, char *c) {
    // Convert lowercase characters to uppercase
    if (*c >= 'a' && *c <= 'z') {
        *c = *c - ('a' - 'A');
    }
}

int main() {
    // Test string
    char test_str[] = "Hello, World!";

	printf("Original string: %s\n", test_str);

    // Call ft_striteri with test string and custom function
    ft_striteri(test_str, my_func);

    // Print transformed string
    printf("Transformed string: %s\n", test_str);

    return 0;
}
*/
