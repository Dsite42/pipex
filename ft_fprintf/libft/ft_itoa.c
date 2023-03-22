/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:26:54 by cgodecke          #+#    #+#             */
/*   Updated: 2023/01/09 14:02:40 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_itoa converts an int to a string.
// Return: The string representing the integer. NULL if the allocation fails.

#include "libft.h"

static int	c_digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	zero_or_neg(char *s, int n_ori, int digits)
{
	if (n_ori == 0)
		s[digits - 1] = 0 + '0';
	if (n_ori < 0)
		s[digits - 1] = '-';
}

char	*ft_itoa(int n)
{
	char	*s;
	int		n_ori;
	int		digits;

	n_ori = n;
	digits = c_digits(n);
	if (n < 0)
		digits++;
	s = (char *)malloc((digits + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	s[digits] = '\0';
	while (n != 0)
	{
		if (n < 0)
			s[digits - 1] = ((n % 10) * -1) + '0';
		else
			s[digits - 1] = (n % 10) + '0';
		n = n / 10;
		digits--;
	}
	zero_or_neg(s, n_ori, digits);
	return (s);
}
