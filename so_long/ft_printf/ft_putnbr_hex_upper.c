/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:11:03 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/26 15:55:40 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_upper(unsigned int n)
{
	char			*hex_digits;
	unsigned int	r;
	int				count;

	count = 0;
	r = n;
	if (r == 0)
		count += 1;
	while (r)
	{
		r = r / 16;
		count++;
	}
	hex_digits = "0123456789ABCDEF";
	if (n >= 16)
		ft_putnbr_hex_upper(n / 16);
	ft_putchar(hex_digits[n % 16]);
	return (count);
}
