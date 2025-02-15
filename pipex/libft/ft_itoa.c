/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:12:38 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/16 10:06:48 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ret;
	long	num;
	int		len;

	len = get_num_len(n);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	num = n;
	if (num == 0)
		ret[0] = '0';
	else if (num < 0)
	{
		ret[0] = '-';
		num = -num;
	}
	while (num)
	{
		ret[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (ret);
}
/*
#include <string.h>
char *itoa(int n)
{
	char 	*str;
	long	num;
	int		len;
	int		sign;

	num = n;
	sign = (n < 0) ? -1 : 1;
	len = (num <= 0) ? 1 : 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (sign == -1)
		num = -num;
	while (len--)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

#include <stdio.h>
void	test_itoa(int n)
{
	char *result_ft_itoa = ft_itoa(n);
	char *result_itoa = itoa(n);

	printf("Input: %d\n", n);
	printf("ft_itoa: %s\n", result_ft_itoa);
	printf("itoa: %s\n", result_itoa);

	if (strcmp(result_ft_itoa, result_itoa) == 0)
		printf("Result: Match\n");
	else
		printf("Result: Mismatch\n");
	printf("\n");

	free(result_ft_itoa);
	free(result_itoa);
}
int main()
{
	int	test_cases[] = {
		0,
		1,
		-1,
		123,
		-123,
		2147483647,
		-2147483648
	};

	int n_cases = sizeof(test_cases)/ sizeof(test_cases[0]);
	int i = 0;
	while (i < n_cases)
	{
		test_itoa(test_cases[i]);
		i++;
	}
	return (0);
}
*/