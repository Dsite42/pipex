/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_lstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:58:36 by chris             #+#    #+#             */
/*   Updated: 2023/02/12 22:21:34 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_lstadd_back adds the node ’new’ at the end of the list.
// Return: None.

#include "pipex.h"

void	pipex_lstadd_back(t_cmd **lst, t_cmd *new)
{
	if (*lst == NULL && new != NULL)
		*lst = new;
	else
	{
		pipex_lstlast(*lst)->next = new;
		new->next = NULL;
	}
}
