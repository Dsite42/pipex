/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awk_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:04:51 by cgodecke          #+#    #+#             */
/*   Updated: 2023/04/05 13:05:51 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	**awk_split(char const *s, char c)
{
	char			*cs;
	char			**arr_split;
	unsigned int	arr_size;
	unsigned int	i;

	i = 0;
	cs = (char *)s;
	arr_size = 2 + 1;
	arr_split = (char **) malloc(arr_size * sizeof(char *));
	if (arr_split == NULL)
		return (NULL);
	cs = cs + sea_start(s, c);
	while (i < arr_size - 1)
	{
		arr_split[i] = ft_substr((char const *) cs, 0, betweenlen(cs, c));
		if (arr_size > 2)
			cs = cs + betweenlen(cs, c) + 1
				+ sea_start(cs + betweenlen(cs, c) + 1, c);
		i++;
		arr_split[i] = ft_substr((char const *) cs + 1, 0, ft_strlen(cs) - 2);
		i++;
	}
	arr_split[i] = NULL;
	return (arr_split);
}
