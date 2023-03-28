/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   of_nstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:12:13 by chris             #+#    #+#             */
/*   Updated: 2023/03/28 12:53:23 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function of_nstrjoin joins n amount of strings together
// using a seperator.
// Return: Returns a string: char *

#include "../pipex.h"

char	*of_nstrjoin(int n, char **strs, char *sep)
{
	char	*joined;
	int		len_join;
	int		i;

	i = 0;
	len_join = 0;
	while (i < n && strs[i] != NULL)
	{
		len_join = len_join + ft_strlen(strs[i]);
		i++;
	}
	len_join = len_join + ((n -1) * ft_strlen(sep) + 1);
	joined = (char *) malloc(len_join * sizeof(char));
	if (joined == NULL)
		return (NULL);
	joined[0] = '\0';
	i = 0;
	while (i < n && strs[i] != NULL)
	{
		ft_strlcat(joined, strs[i], len_join * sizeof(char));
		if (i != n - 1)
			ft_strlcat(joined, sep, len_join * sizeof(char));
		i++;
	}
	return (joined);
}

/*
int	main(void)
{
	int		size;
	char	sep[] = " ";
	char	a[] = "Hello";
	char	b[] = "World";
	char	*strs [2] = {a,b};
	
	size = 2;
	printf("%s\n", ft_strjoin_sn(size, &(*strs), sep));
	printf("%i\n", ft_strlen(ft_strjoin_sn(size, &(*strs), sep)));
}
*/