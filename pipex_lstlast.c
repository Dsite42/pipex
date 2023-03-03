/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_lstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:50:55 by chris             #+#    #+#             */
/*   Updated: 2023/02/12 22:23:12 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_lstlast returns the last node of the list.
// Return: Last node of the list as t_list.

#include "pipex.h"

t_cmd	*pipex_lstlast(t_cmd *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
