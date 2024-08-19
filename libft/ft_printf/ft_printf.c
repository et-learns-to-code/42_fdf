/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:20:29 by etien             #+#    #+#             */
/*   Updated: 2024/08/02 15:05:06 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_specifier(char c, va_list ap);

// Primary function that initializes and wipes the variadic arguments.
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (0);
	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
			count += ft_specifier(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}

// Controller function that determines the specifier after % to
// call the relevant function to process the output.
static int	ft_specifier(char c, va_list ap)
{
	if (c == 'c')
		return (ft_print_char(ap));
	else if (c == 's')
		return (ft_print_string(ap));
	else if (c == 'p')
		return (ft_print_pointer(ap));
	else if (c == 'd' || c == 'i')
		return (ft_print_int(ap));
	else if (c == 'u')
		return (ft_print_unsigned(ap));
	else if (c == 'x')
		return (ft_print_lowerhex(ap));
	else if (c == 'X')
		return (ft_print_upperhex(ap));
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (write(1, &c, 1));
}
