/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:27:44 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:44:56 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 print out string using write 
*/
#include "../includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == (NULL))
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
/*
#include <unistd.h>

int	main(void)
{
	ft_putstr_fd("Hello, world!", 1); 
	ft_putstr_fd("This is an error message.", 2); 
	return (0);
}
*/