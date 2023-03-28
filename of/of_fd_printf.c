/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   of_fd_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:44:31 by chris             #+#    #+#             */
/*   Updated: 2023/03/28 13:00:29 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function of_fd_printf prints out the input arguments
// to a file descripter.
// Return: Return the amout if printed chars as int.

#include "../pipex.h"

static void	put_single(int fd, const char c, size_t *cnt_out)
{
	write(fd, &c, 1);
	*cnt_out = *cnt_out + 1;
}

static void	put_str(int fd, const char *str, size_t *cnt_out)
{
	if (str == NULL)
	{
		write(fd, "(null)", 6);
		*cnt_out = *cnt_out + 6;
	}
	else
	{
		while (*str != '\0')
		{
			write(fd, str, 1);
			*cnt_out = *cnt_out + 1;
			str++;
		}
	}
}

static void	putnbr_base(int fd, long double nb, char *base, size_t *cnt_out)
{
	long double	strlen;

	strlen = ft_strlen(base);
	if (nb < strlen && nb >= 0)
	{
		put_single(fd, base[(long)nb], cnt_out);
	}
	else if (nb >= strlen)
	{
		putnbr_base(fd, nb / strlen, base, cnt_out);
		put_single(fd,
			base[(unsigned long)nb % (unsigned long)strlen], cnt_out);
	}
	else if (ft_strncmp("0123456789", base, 16) == 0)
	{
		put_single(fd, '-', cnt_out);
		putnbr_base(fd, -nb, base, cnt_out);
	}	
	else if (ft_strncmp("0123456789abcdef", base, 16) == 0)
		putnbr_base(fd, -nb, base, cnt_out);
	else
		putnbr_base(fd, (unsigned int)nb, base, cnt_out);
}

static void	print_conversion(int fd, va_list *args,
	char conversion, size_t *cnt_out)
{
	va_list	dest;

	va_copy(dest, *args);
	if (conversion == 'c')
		put_single(fd, va_arg(*args, int), cnt_out);
	if (conversion == 's')
		put_str(fd, va_arg(*args, char *), cnt_out);
	if (conversion == 'i' || conversion == 'd')
		putnbr_base(fd, (long)va_arg(*args, int), "0123456789", cnt_out);
	if (conversion == 'u')
		putnbr_base(fd, (long)va_arg(*args, unsigned int), "0123456789",
			cnt_out);
	if (conversion == 'x')
		putnbr_base(fd,
			(long)va_arg(*args, unsigned int), "0123456789abcdef", cnt_out);
	if (conversion == 'X')
		putnbr_base(fd,
			(long)va_arg(*args, unsigned int), "0123456789ABCDEF", cnt_out);
	if (conversion == 'p')
	{
		put_str(fd, "0x", cnt_out);
		putnbr_base(fd,
			(unsigned long long)va_arg(*args, unsigned long long),
			"0123456789abcdef", cnt_out);
	}
}

int	of_fd_printf(int fd, const char *fmt, ...)
{
	va_list		args;
	size_t		cnt_out;

	cnt_out = 0;
	va_start(args, fmt);
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			put_single(fd, *fmt, &cnt_out);
		else if (*fmt == '%' && *(fmt + 1) == '%')
		{
			fmt++;
			put_single(fd, *fmt, &cnt_out);
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
