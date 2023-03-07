/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:37:36 by chris             #+#    #+#             */
/*   Updated: 2023/02/13 11:31:17 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_lstclear deletes and frees the given node and every
// successor of that node, using the function ’del’ and free(3). Finally, the
// pointer to the list must be set to NULL.
// Return: None.

#include "pipex.h"

void	pipex_lstclear(t_cmd *lst)
{
	t_cmd	*tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		if (lst->program_name != NULL)
			free(lst->program_name);
		if (lst->path_split != NULL)
			fto_free_arr((void **)lst->path_split);
		if (lst->cmd_str != NULL)
			free(lst->cmd_str);
		if (lst->cmd_path != NULL)
			free(lst->cmd_path);
		fto_free_arr((void **)lst->cmd_split);
		if (lst->cmd_split != NULL)
			free(lst->cmd_split);
		free(lst);
		lst = tmp;
	}
	lst = NULL;
}
