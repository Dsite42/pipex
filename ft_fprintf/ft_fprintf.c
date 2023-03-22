/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:44:31 by chris             #+#    #+#             */
/*   Updated: 2023/03/22 15:07:31 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_printf prints out the input arguments.
// Return: Return the amout if printed chars as int.

#include "ft_fprintf.h"

static void	print_conversion(int fd, va_list *args,
	char conversion, size_t *cnt_out)
{
	va_list	dest;

	va_copy(dest, *args);
	if (conversion == 'c')
		ft_put_single(fd, va_arg(*args, int), cnt_out);
	if (conversion == 's')
		ft_put_str(fd, va_arg(*args, char *), cnt_out);
	if (conversion == 'i' || conversion == 'd')
		ft_putnbr_base(fd, (long)va_arg(*args, int), "0123456789", cnt_out);
	if (conversion == 'u')
		ft_putnbr_base(fd, (long)va_arg(*args, unsigned int), "0123456789",
			cnt_out);
	if (conversion == 'x')
		ft_putnbr_base(fd,
			(long)va_arg(*args, unsigned int), "0123456789abcdef", cnt_out);
	if (conversion == 'X')
		ft_putnbr_base(fd,
			(long)va_arg(*args, unsigned int), "0123456789ABCDEF", cnt_out);
	if (conversion == 'p')
	{
		ft_put_str(fd, "0x", cnt_out);
		ft_putnbr_base(fd,
			(unsigned long long)va_arg(*args, unsigned long long),
			"0123456789abcdef", cnt_out);
	}
}

int	ft_fprintf(int fd, const char *fmt, ...)
{
	va_list		args;
	size_t		cnt_out;

	cnt_out = 0;
	va_start(args, fmt);
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			ft_put_single(fd, *fmt, &cnt_out);
		else if (*fmt == '%' && *(fmt + 1) == '%')
		{
			fmt++;
			ft_put_single(fd, *fmt, &cnt_out);
		}
		else
		{
			fmt++;
			print_conversion(fd, &args, *fmt, &cnt_out);
		}
		++fmt;
	}
	va_end(args);
	return (cnt_out);
}
