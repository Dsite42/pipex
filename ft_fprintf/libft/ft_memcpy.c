/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:55:55 by cgodecke          #+#    #+#             */
/*   Updated: 2023/01/06 21:33:48 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_memcpy copies n bytes from memory area src 
//to memory area dest. The memory areas shall not overlap.
// Return: A pointer to the copy.

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return ((char *)dest);
}
