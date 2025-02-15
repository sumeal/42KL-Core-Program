/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:47:57 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/26 15:42:59 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_whatword(char format, va_list args)
{
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_putnbr_hex_lower(va_arg(args, unsigned int)));
	else if (format == 'X')
		return (ft_putnbr_hex_upper(va_arg(args, unsigned int)));
	else if (format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			count;

	va_start (args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += ft_whatword(format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

/*
#include <stdio.h>

int main(void)
{
	int	i = 0;
	int j = 0;
	void *ptr = NULL;
	
	ft_printf("Before\n");
	i = ft_printf("%p\n", ptr);
	ft_printf("After\n");
	j = printf("%p\n", ptr);
	printf ("My ft_pritnf : %d \nactual printf : %d", i, j);
	return (0);
}
*/
/*
#include <stdio.h>

int main()
{
	int num = 12345;
	char *str = "Hello, World!";
	char ch = 'A';
	unsigned int u_num = 4294967295U;
	void *ptr = &num;
	int	a = 0;
	int b = 0;

		
	//a = ft_printf("Combined Test: %u\n", u_num);
	//b = printf("Combined Test: %u\n", u_num);
	
	a = ft_printf("Combined Test: %c %s %p %d %i %u %x %X %%\n"
	, ch, str, ptr, num, num, u_num, num, num);
	b = printf("Combined Test: %c %s %p %d %i %u %x %X %%\n"
	, ch, str, ptr, num, num, u_num, num, num);
	printf("The value of a is %d\n The value of b is %d\n",a ,b);
	
	// Expected output: Combined Test: A Hello, World! 0x... 
	12345 12345 4294967295 3039 3039 %
}
*/
