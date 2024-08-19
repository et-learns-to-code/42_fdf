/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:43:13 by etien             #+#    #+#             */
/*   Updated: 2024/08/02 15:04:40 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// long long is chosen to hold int to avoid integer overflow.
// long long can hold all values of int so no typecasting is necessary.
// Prints a decimal (base 10) number / an integer in base 10.
int	ft_print_int(va_list ap)
{
	long long	n;
	int			sign;

	sign = 0;
	n = va_arg(ap, int);
	if (n < 0)
	{
		sign += write(1, "-", 1);
		n *= -1;
	}
	return (ft_putnbr_base(n, DEC) + sign);
}
