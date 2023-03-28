/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:08:51 by cgodecke          #+#    #+#             */
/*   Updated: 2023/01/04 21:11:03 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_putendl_fd outputs the string ’s’ to the given file
// descriptor followed by a newline.
// Return: None.

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}
