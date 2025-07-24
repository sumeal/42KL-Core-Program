/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:35:12 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/20 15:12:55 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	i = ft_strlen(s1);
	j = 0;
	j = ft_strlen(s2);
	ret = malloc(sizeof(char) * (i + j + 1));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s1, i);
	ft_memcpy(ret + i, s2, j);
	ret[i + j] = '\0';
	return (ret);
}
/*
#include <stdio.h>

int main()
{
	char a[] = "Hello ";
	char b[] = "World !";
	char *c;

	c = ft_strjoin(a, b);
	printf("%s\n", c);
	return (0);
}
*/
