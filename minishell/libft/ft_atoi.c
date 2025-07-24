/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:01:10 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:43:18 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Translate string of number (ASCII) to integer;
no consderation of whtespace and more than two + or -;
The return value is the first consecutive numbers with sign;
*/

#include "../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\f'
		|| *nptr == '\r' || *nptr == '\t' || *nptr == '\v')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + *nptr - '0';
		nptr++;
	}
	return (sign * result);
}
/*
#include <stdio.h>

int main(void)
{
	const char *str0 = "   -1235fhjsf";
	const char *str1 = "    gsg345";
	const char *str2 = "     ----12223gegr";
	const char *str3 = "  \n\t\v\r2242fesfsf";

	printf("str0: %d\n", ft_atoi(str0));
	printf("str1: %d\n", ft_atoi(str1));
	printf("str2: %d\n", ft_atoi(str2));
	printf("str3: %d\n", ft_atoi(str3));

	return (0);
}
*/