/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:01:03 by chris             #+#    #+#             */
/*   Updated: 2023/02/02 10:56:46 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	gnl_strlen(const char *s, char end)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*(s + i) != end && *(s + i) != '\0')
	{
		i++;
	}
	if (end == '\n' && *(s + i) == '\n')
	{
		return (i + 1);
	}
	return (i);
}

int	line_counter(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (*str == '\n')
			i++;
		str++;
	}
	return (i);
}

void	cpy_len(const char *src, char *dest, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
}

char	*gnl_strdup(const char *s, char end)
{
	char	*dup;
	char	*dup_start;
	int		len;

	len = gnl_strlen((char *)s, end);
	dup = malloc((len * sizeof(char)) + 1);
	if (dup == NULL)
		return (NULL);
	dup_start = dup;
	cpy_len(s, dup, len);
	return (dup_start);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*joined;

	joined = (char *) malloc((gnl_strlen(s1, '\0') + gnl_strlen(s2, '\0') + 1)
			* sizeof(char));
	if (joined == NULL)
		return (NULL);
	if (s1 != NULL)
		cpy_len(s1, joined, gnl_strlen(s1, '\0'));
	cpy_len(s2, joined + gnl_strlen(s1, '\0'), gnl_strlen(s2, '\0'));
	if (s1 != NULL)
		free(s1);
	free(s2);
	return (joined);
}
