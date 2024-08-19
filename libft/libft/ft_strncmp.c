/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:11:02 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:23:42 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compares strings up to n characters.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
    // Simple test cases
    const char *s1 = "hello";
    const char *s2 = "hello";
    const char *s3 = "hell";
    const char *s4 = "world";
    const char *s5 = "";
    const char *s6 = "h";

    // Test case 1
    printf("Test case 1: Comparing \"%s\" and \"%s\" with n = 5\n", s1, s2);
    printf("ft_strncmp: %d, strncmp: %d\n\n",
	ft_strncmp(s1, s2, 5), strncmp(s1, s2, 5));

    // Test case 2
    printf("Test case 2: Comparing \"%s\" and \"%s\" with n = 4\n", s1, s3);
    printf("ft_strncmp: %d, strncmp: %d\n\n",
	ft_strncmp(s1, s3, 4), strncmp(s1, s3, 4));

    // Test case 3
    printf("Test case 3: Comparing \"%s\" and \"%s\" with n = 5\n", s1, s4);
    printf("ft_strncmp: %d, strncmp: %d\n\n",
	ft_strncmp(s1, s4, 5), strncmp(s1, s4, 5));

    // Test case 4
    printf("Test case 4: Comparing \"%s\" and \"%s\" with n = 0\n", s1, s2);
    printf("ft_strncmp: %d, strncmp: %d\n\n",
	ft_strncmp(s1, s2, 0), strncmp(s1, s2, 0));

    // Test case 5
    printf("Test case 5: Comparing \"%s\" and \"%s\" with n = 1\n", s5, s6);
    printf("ft_strncmp: %d, strncmp: %d\n\n",
	ft_strncmp(s5, s6, 1), strncmp(s5, s6, 1));

    // Test case 6
    printf("Test case 6: Comparing \"%s\" and \"%s\" with n = 1\n", s6, s5);
    printf("ft_strncmp: %d, strncmp: %d\n\n",
	ft_strncmp(s6, s5, 1), strncmp(s6, s5, 1));

    return (0);
}
*/
