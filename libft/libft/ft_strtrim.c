/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:04:29 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:26:23 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim_str(char const *str, unsigned int start, size_t len);
static int	match_set(const char *set, char c);

// Trims set of characters from beginning and end of string.
char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;

	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (start <= end && match_set(set, s1[start]))
		start++;
	while (end >= start && match_set(set, s1[end]))
		end--;
	return (trim_str(s1, start, (size_t)(end - start + 1)));
}

static char	*trim_str(char const *s1, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (len == 0)
		return (ft_strdup(""));
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	return (str);
}

static int	match_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*
// CANNOT USE SUBSTR, BECAUSE MEMORY BLOCK ALLOCATED BY CALLOC
// WILL BE OVERWRITTEN RESULTING IN MEMORY LEAK

#include <stdio.h>

int main() {
    // Test cases
    char *s1 = "ababaaaMy name is Simonbbaaabba";
    char *set = "ab";
    char *trimmed = ft_strtrim(s1, set);

    // Output the original string and the trimmed string
    printf("Original string: \"%s\"\n", s1);
    printf("Trimmed string: \"%s\"\n", trimmed);

    // Free dynamically allocated memory
    free(trimmed);

    return 0;
}
*/
