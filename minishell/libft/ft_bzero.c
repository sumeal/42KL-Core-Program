/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:01:27 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:42:54 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
set the first lenth bytes of the memory block to zero
return nothing.
*/
#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>

int	main()
{
	char str[20] = "Bonjour!";
	printf("before bzero: %s\n", str);
	ft_bzero(str, 3);
	printf("after bzero: %s\n", str);
	return (0);
}
*/