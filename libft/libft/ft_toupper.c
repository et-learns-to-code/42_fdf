/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:55:43 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:22:43 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts character to uppercase.
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*
#include <stdio.h>
#include <ctype.h>

int main() {
    char test_chars[] = {'a', 'z', 'A', 'Z', '0', '9', '!', ' '};
    size_t num_tests = sizeof(test_chars) / sizeof(test_chars[0]);

    for (size_t i = 0; i < num_tests; i++) {
        char original = test_chars[i];
        char std_result = toupper(original);
        char ft_result = ft_toupper(original);

        printf("Original: %c, Standard toupper: %c, ft_toupper: %c\n",
               original, std_result, ft_result);
    }

    return 0;
}
*/
