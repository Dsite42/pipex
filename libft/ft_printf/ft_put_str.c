/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:11:11 by chris             #+#    #+#             */
/*   Updated: 2023/03/27 18:30:13 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_put_str prints a string and increasing a print counter by
// the amount of printed chars.
// Return: None.

#include "../libft.h"

void	ft_put_str(const char *str, size_t *cnt_out)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*cnt_out = *cnt_out + 6;
	}
	else
	{
		while (*str != '\0')
		{
			write(1, str, 1);
			*cnt_out = *cnt_out + 1;
			str++;
		}
	}
}
