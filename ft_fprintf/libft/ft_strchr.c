/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:46:09 by cgodecke          #+#    #+#             */
/*   Updated: 2023/01/06 21:32:54 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_strchr searchs the first occurance of the character
// in a string s.
// Return: A pointer to the matching character or NULL if it is not found.

char	*ft_strchr(const char *s, int c)
{
	char	*cs;

	cs = (char *)s;
	c = c % 256;
	while (*cs != '\0')
	{
		if (*cs == c)
			return (cs);
		cs++;
	}
	if (*cs == '\0' && c == '\0')
		return (cs);
	return (0);
}
