/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:18:34 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:24:52 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Finds first occurrence of substring.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack [i + j] && haystack[i + j] == needle[j]
			&& (i + j < len))
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int main() {
  char *haystack = "This is a haystack example";
  char *needle1 = "stack";
  char *needle2 = "xyz";
  size_t len = 20;

  // Test with strnstr from libc
  char *result_libc = strnstr(haystack, needle1, len);
  printf("strnstr(haystack, needle1, len): %s\n", result_libc != NULL ?
  result_libc : "(null)");
  printf("result: %s\n", result_libc);
  result_libc = strnstr(haystack, needle2, len);
  printf("strnstr(haystack, needle2, len): %s\n", result_libc != NULL ?
  result_libc : "(null)");
  printf("result: %s\n", result_libc);

  // Test with your ft_strnstr function
  char *result_ft = ft_strnstr(haystack, needle1, len);

  printf("ft_strnstr(haystack, needle1, len): %s\n", result_ft != NULL ?
  result_ft : "(null)");
  printf("result: %s\n", result_ft);
  result_ft = ft_strnstr(haystack, needle2, len);
  printf("ft_strnstr(haystack, needle2, len): %s\n", result_ft != NULL ?
  result_ft : "(null)");
  printf("result: %s\n", result_ft);
  return 0;
}
*/
