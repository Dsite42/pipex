/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:04:51 by cgodecke          #+#    #+#             */
/*   Updated: 2023/01/07 13:34:00 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_split creates a new array of strings that have been split
// from a string seperated by a char. The array ends with a NULL pointer.
// Return: Pointer to the new array of new strings resulting from the split.
// NULL if the allocation fails.

#include "libft.h"

static unsigned int	str_count(char const *str, char c)
{
	unsigned int	i;
	unsigned int	cnt;

	i = 0;
	cnt = 0;
	if (str[0] == '\0')
		return (cnt);
	while (str[i] == c)
		i++;
	if (str[i] == '\0')
		return (cnt);
	while (str[i] != '\0')
	{
		if ((str[i] == c) && (str[i + 1] != c && str[i + 1] != '\0'))
			cnt++;
		i++;
	}
	return (cnt + 1);
}

static unsigned int	betweenlen(char const *str, char sep)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != sep)
		i++;
	return (i);
}

static unsigned int	sea_start(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	if (c == '\0')
		return (i);
	while (s[i] == c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char			*cs;
	char			**arr_split;
	unsigned int	arr_size;
	unsigned int	i;

	i = 0;
	cs = (char *)s;
	arr_size = str_count(cs, c) + 1;
	arr_split = (char **) malloc(arr_size * sizeof(char *));
	if (arr_split == NULL)
		return (NULL);
	cs = cs + sea_start(s, c);
	while (i < arr_size - 1)
	{
		arr_split[i] = ft_substr((char const *) cs, 0, betweenlen(cs, c));
		cs = cs + betweenlen(cs, c) + 1
			+ sea_start(cs + betweenlen(cs, c) + 1, c);
		i++;
	}
	arr_split[i] = NULL;
	return (arr_split);
}
