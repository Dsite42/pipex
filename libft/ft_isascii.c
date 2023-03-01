/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:01:15 by coder             #+#    #+#             */
/*   Updated: 2022/12/16 11:44:11 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_isascii checks if the character is an ASCII (0-127).
// Return: 1 if yes 0 if not as int.

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
