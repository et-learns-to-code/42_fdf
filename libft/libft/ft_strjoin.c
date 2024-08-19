/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:39:43 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:26:03 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Joins two strings.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	return (str);
}

/*
#include <stdio.h>

int main(void) {
    const char *str1 = "Hello, ";
    const char *str2 = "world!";
    char *result = ft_strjoin(str1, str2);

    if (result) {
        printf("Joined string: '%s'\n", result);
        free(result);
    } else {
        printf("Failed to allocate memory for joined string.\n");
    }

    return 0;
}
*/
