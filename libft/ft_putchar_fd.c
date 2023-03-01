/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:08:51 by cgodecke          #+#    #+#             */
/*   Updated: 2023/01/04 21:10:57 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_putchar_fd outputs the character ’c’ to the given file
// descriptor.
// Return: None.

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
