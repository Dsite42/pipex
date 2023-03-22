/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:37:36 by chris             #+#    #+#             */
/*   Updated: 2023/01/07 13:06:33 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_lstdelone takes as a parameter a node and frees the memory
// of the node’s content using the function ’del’ given as a parameter and free
// the node. The memory of ’next’ is not freed.
// Return: None.

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del != NULL)
		del(lst->content);
	free(lst);
}
