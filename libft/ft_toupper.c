/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:20:34 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/15 15:46:47 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/*
#include <stdio.h>

int main()
{
	int a = 'a';
	int b = 'A';

	printf("%c\n", ft_toupper(a));
	printf("%c\n", ft_toupper(b));
	return (0);
}
*/
