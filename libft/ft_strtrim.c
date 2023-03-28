/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:46:57 by cgodecke          #+#    #+#             */
/*   Updated: 2023/01/06 11:22:57 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_strtrim creates a copy of a string, but removed the
// characters specified in set from the beginning and end of the string.
// Return: Pointer to the trimmed string. NULL if the allocation fails.

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	begin;
	unsigned int	end;
	unsigned int	cpy_len;
	char			*trim;

	begin = 0;
	end = ft_strlen(s1) - 1;
	if (ft_strncmp(s1, "", 1) == 0 || ft_strncmp(set, "", 1) == 0)
		return (ft_strdup(s1));
	while (ft_strchr(set, s1[begin]) != 0)
	{
		if (s1[begin] == '\0')
			break ;
		begin++;
	}
	if (begin - 1 == end)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end]) != 0)
		end--;
	cpy_len = end - begin + 1;
	trim = (char *) malloc((cpy_len + 1) * sizeof(char));
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, &s1[begin], cpy_len + 1);
	return (trim);
}
