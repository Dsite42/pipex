/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:58:36 by chris             #+#    #+#             */
/*   Updated: 2023/01/06 21:33:06 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_lstadd_back adds the node ’new’ at the end of the list.
// Return: None.

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL && new != NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
