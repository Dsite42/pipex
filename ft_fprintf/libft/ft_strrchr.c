/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:46:09 by cgodecke          #+#    #+#             */
/*   Updated: 2023/01/06 14:12:00 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_strrchr searchs the last occurance of the character
// in a string s.
// Return: A pointer to the matching character or NULL if it is not found.

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	size_t	i;

	c = c % 256;
	i = 0;
	len = ft_strlen((char *)s);
	if (s[len] == '\0' && c == '\0')
		return ((char *)&s[len]);
	while (len >= i)
	{
		if (s[len] == c)
			return ((char *)&s[len]);
		if (len == 0)
			break ;
		len--;
	}
	return (NULL);
}
