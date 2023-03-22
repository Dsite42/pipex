/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_single.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:11:11 by chris             #+#    #+#             */
/*   Updated: 2023/03/22 14:39:57 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_put_single prints one char and increasing a print counter.
// Return: None.

#include "ft_fprintf.h"

void	ft_put_single(int fd, const char c, size_t *cnt_out)
{
	write(fd, &c, 1);
	*cnt_out = *cnt_out + 1;
}
