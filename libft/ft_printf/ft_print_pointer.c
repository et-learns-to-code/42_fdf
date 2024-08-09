/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:43:59 by etien             #+#    #+#             */
/*   Updated: 2024/08/02 15:04:44 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// On a 64-bit system, pointers are typically 64 bits (8 bytes) in size,
// so they are stored as unsigned long or unsigned long long.
// Prints a void * pointer address in hexadecimal format.
int	ft_print_pointer(va_list ap)
{
	unsigned long long	n;

	n = (unsigned long long) va_arg(ap, void *);
	write(1, "0x", 2);
	return (ft_putnbr_base(n, HEX) + 2);
}
