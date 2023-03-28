/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:44:31 by chris             #+#    #+#             */
/*   Updated: 2023/03/27 18:30:07 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_printf prints out the input arguments.
// Return: Return the amout if printed chars as int.

#include "../libft.h"

static int	check_flags(const char **fmt, char *conv, char *flags)
{
	char	*ref_flags;
	char	*ref_conversions;
	int		i;

	i = 0;
	ref_flags = "-0.# +";
	ref_conversions = "cspdiuxX";
	while (ft_strchr(ref_conversions, **fmt) == NULL)
	{
		if (ft_strchr(ref_flags, **fmt) == NULL)
			break ;
		flags[i] = *ft_strchr(ref_flags, **fmt);
		*fmt = *fmt + 1;
		i++;
	}
	if (ft_strchr(ref_conversions, **fmt) == NULL)
	{
		while (ft_strchr(ref_conversions, **fmt) == NULL)
		{
			*fmt = *fmt + 1;
		}
		return (1);
	}
	*conv = **fmt;
	return (0);
}

static void	print_hex(va_list *args, char conv, char *flags, size_t *cnt_out)
{
	va_list	dest;

	va_copy(dest, *args);
	if (conv == 'x')
	{
		ft_print_flags(va_arg(dest, unsigned int), flags, conv, cnt_out);
		ft_putnbr_base((long)va_arg(*args, unsigned int),
			"0123456789abcdef", cnt_out);
	}
	if (conv == 'X')
	{
		ft_print_flags(va_arg(dest, unsigned int), flags, conv, cnt_out);
		ft_putnbr_base((long)va_arg(*args, unsigned int),
			"0123456789ABCDEF", cnt_out);
	}
	if (conv == 'p')
	{
		ft_put_str("0x", cnt_out);
		ft_putnbr_base((unsigned long long)va_arg(*args, unsigned long long),
			"0123456789abcdef", cnt_out);
	}
}

static void	print_csidu(va_list *args, char conv, char *flags, size_t *cnt_out)
{
	va_list	dest;

	va_copy(dest, *args);
	if (conv == 'c')
		ft_put_single(va_arg(*args, int), cnt_out);
	if (conv == 's')
		ft_put_str(va_arg(*args, char *), cnt_out);
	if (conv == 'i' || conv == 'd')
	{
		ft_print_flags(va_arg(dest, int), flags, conv, cnt_out);
		ft_putnbr_base((long)va_arg(*args, int), "0123456789", cnt_out);
	}
	if (conv == 'u')
	{
		ft_print_flags(va_arg(dest, unsigned int), flags, conv, cnt_out);
		ft_putnbr_base((long)va_arg(*args, unsigned int),
			"0123456789", cnt_out);
	}
}

static void	f_conversion(const char **fmt, va_list *args,
	char *flags, size_t *cnt_out)
{
	int		isflagok;
	char	conv;

	if (*(*fmt + 1) == '\0')
		return ;
	*fmt = *fmt + 1;
	isflagok = !check_flags(fmt, &conv, flags);
	if (isflagok == 0 && **fmt != '\0')
	{
		ft_put_single(' ', cnt_out);
	}
	if (isflagok == 1)
	{
		if (conv == 'x' || conv == 'X' || conv == 'p')
			print_hex(args, conv, flags, cnt_out);
		else
			print_csidu(args, conv, flags, cnt_out);
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	char		flags[6];
	size_t		cnt_out;

	cnt_out = 0;
	va_start(args, fmt);
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			ft_put_single(*fmt, &cnt_out);
		else if (*fmt == '%' && *(fmt + 1) == '%')
		{
			fmt++;
			ft_put_single(*fmt, &cnt_out);
		}
		else
		{
			ft_memset(flags, '\0', sizeof flags);
			f_conversion(&fmt, &args, flags, &cnt_out);
		}
		++fmt;
	}
	va_end(args);
	return (cnt_out);
}
