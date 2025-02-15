/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:18:03 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/26 08:51:04 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int				i;
	unsigned long	addr;
	char			*hex_digits;
	int				count;
	char			buffer[17];

	addr = (unsigned long)ptr;
	if (addr == 0)
		return (ft_putstr("(nil)"));
	hex_digits = "0123456789abcdef";
	buffer[16] = '\0';
	i = 15;
	while (addr != 0)
	{
		buffer[i] = hex_digits[addr % 16];
		addr /= 16;
		i--;
	}
	count = ft_putstr("0x");
	count += ft_putstr(&buffer[i + 1]);
	return (count);
}
