/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   of_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:50:37 by chris             #+#    #+#             */
/*   Updated: 2023/03/28 12:53:17 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The function of_free_arr frees all contents of an void **array and itself.
// Return: none.
#include "../pipex.h"

void	of_free_arr(void **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	if (arr != NULL)
		free(arr);
}
