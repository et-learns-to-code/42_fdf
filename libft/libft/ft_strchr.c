/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:07:35 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:23:24 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Finds first occurrence of character.
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "Hello, world!";
    int ch = 'o';
    int ch_not_found = 'x';
    int ch_null = '\0';

    char *result_std = strchr(str, ch);
    char *result_ft = ft_strchr(str, ch);
    printf("Standard strchr: %s, ft_strchr: %s\n",
	result_std, result_ft);

    result_std = strchr(str, ch_not_found);
    result_ft = ft_strchr(str, ch_not_found);
    printf("Standard strchr (not found): %s, ft_strchr: %s\n",
	result_std, result_ft);

    result_std = strchr(str, ch_null);
    result_ft = ft_strchr(str, ch_null);
    printf("Standard strchr (null character): %s, ft_strchr: %s\n",
	result_std, result_ft);

    return 0;
}
*/
