/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:57:38 by chris             #+#    #+#             */
/*   Updated: 2023/03/28 14:44:08 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

// This function ft_putnbr_base prints a number by converting it to an other 
// base system.
// Return: None.
void	ft_putnbr_base(long double nb, char *base, size_t *cnt_out);

// This function ft_put_single prints one char and increasing a print counter.
// Return: None.
void	ft_put_single(const char c, size_t *cnt_out);

// This function ft_put_str prints a string and increasing a print counter by
// the amount of printed chars.
// Return: None.
void	ft_put_str(const char *str, size_t *cnt_out);

// This function ft_printf prints out the input arguments.
// Return: Return the amout if printed chars as int.
int		ft_printf(const char *fmt, ...);
#endif
