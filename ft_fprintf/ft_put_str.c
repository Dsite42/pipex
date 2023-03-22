/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:11:11 by chris             #+#    #+#             */
/*   Updated: 2023/03/22 14:39:59 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_put_str prints a string and increasing a print counter by
// the amount of printed chars.
// Return: None.

#include "ft_fprintf.h"

void	ft_put_str(int fd, const char *str, size_t *cnt_out)
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
