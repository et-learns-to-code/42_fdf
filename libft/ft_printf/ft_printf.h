/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:14:42 by etien             #+#    #+#             */
/*   Updated: 2024/08/01 13:31:44 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define HEX_U "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
int		ft_print_char(va_list ap);
int		ft_print_int(va_list ap);
int		ft_print_lowerhex(va_list ap);
int		ft_print_pointer(va_list ap);
int		ft_print_string(va_list ap);
int		ft_print_unsigned(va_list ap);
int		ft_print_upperhex(va_list ap);
int		ft_putnbr_base(unsigned long long n, const char *base);
size_t	printf_strlen(const char *s);

#endif
