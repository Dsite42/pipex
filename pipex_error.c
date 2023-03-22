/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:19:16 by cgodecke          #+#    #+#             */
/*   Updated: 2023/03/22 14:49:07 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_error(int shall_exit, char *message,
			int isstrerror, int exit_code)
{
	if (isstrerror == 1)
	{
		ft_fprintf(2, "%s Error code:%i %s\n", message,
			exit_code, strerror(exit_code));
	}
	else
		ft_fprintf(2, "pipex: %s\n", message);
	if (shall_exit == 1)
		exit(exit_code);
}
