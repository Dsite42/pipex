/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_lstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:58:36 by chris             #+#    #+#             */
/*   Updated: 2023/03/25 18:45:30 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_tmpnew creates a new node. The member variable ’content’
// is // initialized with the value of the parameter ’content’.
// The variable ’next’ is initialized to NULL.
// Return: The new node as t_list.

#include "pipex.h"

t_cmd	*pipex_lstnew(char *content)
{
	t_cmd	*tmp;

	tmp = (t_cmd *) malloc(sizeof(t_cmd));
	if (tmp == NULL)
		return (NULL);
	tmp->program_name = NULL;
	tmp->path_split = NULL;
	tmp->cmd_str = ft_strdup(content);
	tmp->cmd_split = NULL;
	tmp->cmd_path = NULL;
	tmp->next = NULL;
	return (tmp);
}
