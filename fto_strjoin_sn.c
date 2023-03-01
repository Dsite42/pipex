/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_strjoin_sn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:12:13 by chris             #+#    #+#             */
/*   Updated: 2023/03/01 18:52:15 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"
#include <strings.h>

char	*ft_strjoin_sn(int size, char **strs, char *sep)
{
	char	*joined;
	int		len_join;
	int		i;

printf("test:%s\n", strs[0]);
	i = 0;
	len_join = 0;
	while (i < size && strs[i] != NULL)
	{
		len_join = len_join + ft_strlen(strs[i]);
		i++;
	}

	len_join = len_join + ((size -1) * ft_strlen(sep) + 1);
	joined = (char *) malloc(len_join * sizeof(char));
	if (joined == NULL)
		return (NULL);
	joined[0] = '\0';
	i = 0;
	while (i < size && strs[i] != NULL)
	{
		ft_strlcat(joined, strs[i], len_join * sizeof(char));
		if (i != size - 1)
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