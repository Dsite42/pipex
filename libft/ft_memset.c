/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:46:09 by cgodecke          #+#    #+#             */
/*   Updated: 2023/01/04 22:32:15 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_memset overwrites n bytes in the memory from the pointer
// by constant byte c. 
// Return: pointer to memory area prt.

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	while (n > 0)
	{
		((char *)s)[n - 1] = c;
		n--;
	}
	return (s);
}
