/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:59:19 by chris             #+#    #+#             */
/*   Updated: 2023/03/27 18:30:04 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_print_flags prints a string or char depending on the input
// flags and increasing a print counter by the amount of printed chars.
// Return: None.

#include "../libft.h"

void	ft_print_flags(int dest_val, char *flags, char conv, size_t *cnt_out)
{
	if (ft_strlen(flags) == 0)
		return ;
	if ((conv == 'i' || conv == 'd') && ft_strchr(flags, ' ')
		&& !ft_strchr(flags, '+') && dest_val >= 0)
	{
		ft_put_single(' ', cnt_out);
	}
	if ((conv == 'i' || conv == 'd') && ft_strchr(flags, '+') && dest_val >= 0)
	{
		ft_put_single('+', cnt_out);
	}
	if (conv == 'x' && dest_val != 0)
	{
		ft_put_str("0x", cnt_out);
	}
	if (conv == 'X' && dest_val != 0)
	{
		ft_put_str("0X", cnt_out);
	}
}
