/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:11:18 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/26 15:54:43 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int	r;
	int				count;

	count = 0;
	r = n;
	if (r == 0)
		count += 1;
	while (r)
	{
		r = r / 10;
		count++;
	}
	if (n > 9)
		ft_putnbr_unsigned(n / 10);
	ft_putchar(n % 10 + '0');
	return (count);
}
