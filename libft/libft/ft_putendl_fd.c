/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:59:23 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:30:12 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Writes string with newline to file descriptor.
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

/*
#include <stdio.h>

// Declare ft_putendl_fd for testing purposes
void ft_putendl_fd(char *s, int fd);

int main() {
    char *str = "Hello, World!"; // String to output
    int fd = 1;                   // File descriptor (1 for stdout)

    printf("Testing ft_putendl_fd:\n");

    // Output string with newline using ft_putendl_fd
    printf("Output to stdout: ");
    fflush(stdout); // Flush the stdout buffer
    ft_putendl_fd(str, fd);

    return 0;
}
*/
