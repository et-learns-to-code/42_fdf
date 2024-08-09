/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:52:52 by etien             #+#    #+#             */
/*   Updated: 2024/07/18 14:33:56 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);

// Converts string to integer.
int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (sign * result);
}

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

/*
#include <stdio.h>

int main() {
    const char *test_cases[] = {
        "42",
        "    -42",
        "4193 with words",
        "words and 987",
        "+123",
        "  +0",
        "-2147483648",
        "2147483647",
        NULL
    };

    for (int i = 0; test_cases[i] != NULL; i++) {
        printf("Input: '%s' => Output: %d\n", test_cases[i],
		ft_atoi(test_cases[i]));
    }

    return 0;
}
*/
