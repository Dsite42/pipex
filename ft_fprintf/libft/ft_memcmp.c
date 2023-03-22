/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:20:42 by cgodecke          #+#    #+#             */
/*   Updated: 2023/01/05 18:26:53 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_memcmp compares the first n bytes (each interpreted 
// as unsigned char) of the memory areas s1 and s2.
// Return: Difference between the first pair of bytes (interpreted as unsigned
//char) that differ in s1 and s2 as int. If n is zero, the return value is zero.

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*cs1;
	char	*cs2;
	size_t	i;
	int		diff_val;

	cs1 = (char *)s1;
	cs2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (cs1[i] != cs2[i])
		{
			diff_val = (unsigned char)cs1[i] - (unsigned char)cs2[i];
			return (diff_val);
		}
		i++;
	}
	return (0);
}
