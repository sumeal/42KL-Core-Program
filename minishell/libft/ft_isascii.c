/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:07:10 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:43:44 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
To test ascii
*/

#include "../includes/libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_isascii(65));
	printf("%d\n", ft_isascii(345));
	return (0);
}
*/