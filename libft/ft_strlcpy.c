/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:37:38 by coder             #+#    #+#             */
/*   Updated: 2023/01/04 21:29:58 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_strlcpy copies n-1 bytes to a dst string by 0 terminating
// the results. src must be NUL-terminated.
// Return: The total length of the string they tried to create (length of src).

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	length;

	i = 0;
	length = ft_strlen(src);
	while (size > 0 && i < size - 1 && i < length)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
	{
		dst[i] = '\0';
	}
	return (length);
}
