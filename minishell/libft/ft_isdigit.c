/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:33:04 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:43:48 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
    char c1 = '5';
    char c2 = 'a';
    
    printf("%c is a digit: %d\n", c1, isdigit(c1));
    printf("%c is a digit: %d\n", c2, isdigit(c2));
    
    return 0;
}
*/