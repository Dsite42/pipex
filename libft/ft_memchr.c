/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:46:09 by cgodecke          #+#    #+#             */
/*   Updated: 2023/01/04 22:47:44 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_memchr scans n bytes of the memory area pointed to by prt
// for the first instance of c.
// Return: A pointer to the matching byte or NULL if the character
// does not occur in the given memory area.

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if (*(const unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
		n--;
	}
	return (0);
}
