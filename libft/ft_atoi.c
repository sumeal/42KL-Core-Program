/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:25:18 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/15 09:47:47 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
#include <stdio.h>
 void test_atoi(const char *str)
 { 
	int result_libft = ft_atoi(str);
	int result_std = atoi(str);

	printf("Input: \"%s\"\n", str);
	printf("ft_atoi: %d\n", result_libft);
	printf("atoi: %d\n", result_std);

	if (result_libft == result_std)
		printf("Result: Match\n");
	else
		printf("Result: Mismatch\n");
	printf("\n");
 }

 int main(void)
 {
	const char	*test_cases[] = {
		"42",
		"   42",
		"   -42",
		"4193 with words",
		"words and 987",
		"-2147483648",
		"2147483647",
		"0",
		"+42",
		"---+42",
		NULL
	};

	int	i = 0;
	while (test_cases[i])
	{
		test_atoi(test_cases[i]);
		i++;
	}
	return (0);
 }
 */
