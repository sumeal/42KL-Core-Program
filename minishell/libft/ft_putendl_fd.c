/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:34:43 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:44:48 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The ft_putendl_fd function outputs a string to the specified file descriptor, 
appending a newline character at the end
*/
#include "../includes/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}
/*
int main(void)
{
	ft_putendl_fd("hello", 1);
	ft_putendl_fd("hello world", 2);

	return (0);
}
*/