/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:49:36 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:45:18 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 iterate over each character of a string and apply a function to each character
 both the character and its index as arguments
*/

#include "../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

void *test(unsigned int i, char *s)
{
	if (i % 2 == 0)
		*s = 'a';
	else
		*s = 'b';
}

int main(void)
{
	char	s[] = "hello world";
	ft_striteri(s,test);
	printf("the string is : %s\n", s);
	return (0);

}
*/