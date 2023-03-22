/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:37:36 by chris             #+#    #+#             */
/*   Updated: 2023/01/07 13:23:29 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_lstmap iterates the list ’lst’ and applies the function ’f’
// on the content of each node. Creates a new list resulting of the successive
// applications of the function ’f’. The ’del’ function is used to delete the
// content of a node if needed.
// Return: The new list. NULL if the allocation fails.

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;
	void	*fres;

	newlst = NULL;
	while (lst != NULL)
	{
		fres = f(lst->content);
		newnode = ft_lstnew(fres);
		if (newnode == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		if (newlst == NULL)
			newlst = newnode;
		else
			ft_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
}
