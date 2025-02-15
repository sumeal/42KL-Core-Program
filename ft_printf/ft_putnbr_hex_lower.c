/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_lower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:11:10 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/26 15:55:24 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_lower(unsigned int n)
{
	unsigned int	r;
	int				count;
	char			*hex_digits;

	count = 0;
	r = n;
	if (r == 0)
		count += 1;
	while (r)
	{
		r = r / 16;
		count++;
	}
	hex_digits = "0123456789abcdef";
	if (n >= 16)
		ft_putnbr_hex_lower(n / 16);
	ft_putchar(hex_digits[n % 16]);
	return (count);
}
