/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:46:03 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:29:52 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Writes string to file descriptor.
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

/*
#include <stdio.h>

int main() {
    char *str = "Hello, World!"; // String to output
    int fd = 1;                   // File descriptor (1 for stdout)

    // Testing message 1
    printf("Testing ft_putstr_fd:\n");

    // Outputting message 2
    printf("Output to stdout: ");
    fflush(stdout); // Ensure previous printf is flushed

    // Outputting string using ft_putstr_fd
    ft_putstr_fd(str, fd);
    printf("\n");

    return 0;
}
*/
