/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:12:48 by cgodecke          #+#    #+#             */
/*   Updated: 2023/01/06 18:41:02 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_strnstr search for a string in another string withhin the
// first n characters.
// Return: A pointer to the start of the searched string or NULL if the string
// is not found or the srource string if to_find is emty.

#include "libft.h"

static void	check_goback(size_t *i, size_t *j, char **str, size_t *found)
{
	if (*found == 1)
	{
		*str = *str - *j;
		*i = *i - *j;
	}
	*found = 0;
	*j = 0;
}

static char	*long_search(size_t to_find_len, char *str, char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	found;

	i = 0;
	j = 0;
	while (i < n && *str != '\0')
	{
		if (*str == to_find[j])
		{
			if (j == 0)
				found = 1;
			if (found == 1 && j == to_find_len - 1)
				return (str - (to_find_len - 1));
			j++;
		}
		else
			check_goback(&i, &j, &str, &found);
		str++;
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *ccstr, const char *ccto_find, size_t n)
{
	size_t	to_find_len;
	char	*str;
	char	*to_find;

	str = (char *)ccstr;
	to_find = (char *)ccto_find;
	to_find_len = ft_strlen(to_find);
	if (to_find_len == 0 || (to_find_len == 1 && *str == *to_find))
		return (str);
	else
		return (long_search(to_find_len, str, to_find, n));
}
