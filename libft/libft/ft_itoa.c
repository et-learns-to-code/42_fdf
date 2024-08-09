/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:14:47 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:27:21 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long nbr);

// nbr is made into long data type to avoid issues with INT_MIN and INT_MAX

// Converts integer to string.
char	*ft_itoa(int n)
{
	long	nbr;
	int		len;
	char	*str;
	int		i;

	nbr = n;
	len = int_len(nbr);
	str = ft_calloc((size_t)(len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
	}
	if (nbr == 0)
		str [0] = '0';
	i = len - 1;
	while (nbr > 0)
	{
		str[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	return (str);
}

static int	int_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
	{
		count++;
	}
	while (nbr > 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

/*
#include <stdio.h>

// Main function to test the ft_itoa function
int main() {
    int test_values[] = {123, -456, 0, 78910, -2147483648};
    char *result;
    for (int i = 0; i < sizeof(test_values) / sizeof(test_values[0]); i++) {
        result = ft_itoa(test_values[i]);
        if (result) {
            printf("ft_itoa(%d) = %s\n", test_values[i], result);
            free(result); // Don't forget to free the allocated memory
        } else {
            printf("ft_itoa(%d) failed to allocate memory\n", test_values[i]);
        }
    }
    return 0;
}
*/
