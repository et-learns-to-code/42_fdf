/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:44:58 by etien             #+#    #+#             */
/*   Updated: 2024/08/02 15:04:34 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Prints a number in hexadecimal (base 16) lowercase format.
int	ft_print_lowerhex(va_list ap)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	return (ft_putnbr_base(n, HEX));
}

// Prints a number in hexadecimal (base 16) uppercase format.
int	ft_print_upperhex(va_list ap)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	return (ft_putnbr_base(n, HEX_U));
}
