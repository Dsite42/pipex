/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:37:07 by cgodecke          #+#    #+#             */
/*   Updated: 2023/01/04 21:11:28 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_strdup duplicates a string.
// Return: A pointer to the duplicated string. It returns NULL if insufficient
// memory was available.

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*dup_start;

	dup = malloc((ft_strlen((char *)s) * sizeof(char)) + 1);
	if (dup == NULL)
		return (NULL);
	dup_start = dup;
	while (*s)
	{
		*dup = *s;
		s++;
		dup++;
	}
	*(dup) = '\0';
	return (dup_start);
}
