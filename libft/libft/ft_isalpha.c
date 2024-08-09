/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:52:56 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:17:31 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Checks if character is alphabetic.
int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/*
#include <stdio.h>
#include <ctype.h>

int main() {
    char test_chars[] = {'A', 'b', '3', '$', 'z'};
    int num_test_chars = sizeof(test_chars) / sizeof(test_chars[0]);

    printf("Testing ft_isalpha function:\n");
    for (int i = 0; i < num_test_chars; i++)
	{
        printf("ft_isalpha('%c') = %d\n", test_chars[i],
				ft_isalpha(test_chars[i]));
    }

    return 0;
}
*/
