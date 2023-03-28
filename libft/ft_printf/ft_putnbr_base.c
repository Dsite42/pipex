/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:28:53 by chris             #+#    #+#             */
/*   Updated: 2023/03/27 18:30:16 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function ft_putnbr_base prints a number by converting it to an other 
// base system.
// Return: None.

#include "../libft.h"

void	ft_putnbr_base(long double nb, char *base, size_t *cnt_out)
{
	long double	strlen;

	strlen = ft_strlen(base);
	if (nb < strlen && nb >= 0)
	{
		ft_put_single(base[(long)nb], cnt_out);
	}
	else if (nb >= strlen)
	{
		ft_putnbr_base(nb / strlen, base, cnt_out);
		ft_put_single(base[(unsigned long)nb % (unsigned long)strlen], cnt_out);
	}
	else if (ft_strncmp("0123456789", base, 16) == 0)
	{
		ft_put_single('-', cnt_out);
		ft_putnbr_base(-nb, base, cnt_out);
	}	
	else if (ft_strncmp("0123456789abcdef", base, 16) == 0)
		ft_putnbr_base(-nb, base, cnt_out);
	else
		ft_putnbr_base((unsigned int)nb, base, cnt_out);
}
