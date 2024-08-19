/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:36:14 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:29:40 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Writes character to file descriptor.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int main() {
    char c = 'A'; // Character to print
    int fd = 1;   // File descriptor (1 for stdout)

	write(1, "Testing ft_putchar_fd:\n", 24);
    write(1, "Output to stdout: ", 18);
    ft_putchar_fd(c, fd);
    write(1, "\n", 1);

    return 0;
}
*/
