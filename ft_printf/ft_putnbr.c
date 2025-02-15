/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:47:24 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/28 09:04:53 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(int r)
{
	int	count;

	count = 0;
	if (r == 0)
		return (1);
	while (r)
	{
		if (r < 0)
		{
			count++;
			r = -r;
		}
		while (r)
		{
			r = r / 10;
			count++;
		}
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	r;
	int	count;

	r = n;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar(n % 10 + '0');
	count = ft_count(r);
	return (count);
}
