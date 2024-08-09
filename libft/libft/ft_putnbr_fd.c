/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:17:00 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:30:26 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Writes integer to file descriptor.
void	ft_putnbr_fd(int n, int fd)
{
	char	nbr;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
	}
	nbr = (n % 10) + '0';
	write(fd, &nbr, 1);
}

/*
#include <stdio.h>

int main() {
    int fd = 1; // File descriptor (1 for stdout)

    // Test cases
    int test_cases[] = {0, 123, -456, 2147483647, -2147483648};

    // Testing ft_putnbr_fd with each test case
    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        printf("Testing ft_putnbr_fd with test case %d:\n", test_cases[i]);
        ft_putnbr_fd(test_cases[i], fd);
        printf("\n");
    }

    return 0;
}
*/
