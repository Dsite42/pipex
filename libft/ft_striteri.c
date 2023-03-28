/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:10:10 by chris             #+#    #+#             */
/*   Updated: 2022/12/23 17:25:05 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_striteri applies function f to each character of the string,
// so that it can be manipulated.
// Return: None.

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (*s != '\0')
	{
		f(i, s);
		s++;
		i++;
	}
}
