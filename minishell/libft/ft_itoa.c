/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:46:53 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:44:00 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

/*
two func:
1. calculate how many numbers in the integer
2. using malloc to allocate the raw memory block
3. considering the int mininum value(-2147483648)
	tranverse to positive value(using long(64bits))
*/
static int	count_num(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*c;
	int		count;
	long	num;

	num = (long)n;
	count = count_num(n);
	c = (char *)malloc(count + 1);
	if (!c)
		return (NULL);
	c[count] = '\0';
	if (num < 0)
	{
		c[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		count--;
		c[count] = num % 10 + '0';
		num = num / 10;
	}
	if (n == 0)
		c[0] = '0';
	return (c);
}

/*
#include <stdio.h>

int	main(void)
{
	int numbers[] = {123, -456, 0, 2147483647, -2147483648};
	char *result;
	int i;

	for (i = 0; i < 5; i++)
	{
		result = ft_itoa(numbers[i]);
		if (result)
		{
			printf("ft_itoa(%d) = %s\n", numbers[i], result);
			free(result);
		}
		else
		{
			printf("Memory allocation failed for ft_itoa(%d)\n", numbers[i]);
		}
	}
	return (0);
*/