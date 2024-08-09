/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:02:47 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:22:59 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts character to lowercase.
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
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
        char std_result = tolower(original);
        char ft_result = ft_tolower(original);

        printf("Original: %c, Standard tolower: %c, ft_tolower: %c\n",
               original, std_result, ft_result);
    }

    return 0;
}
*/
