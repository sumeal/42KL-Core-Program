/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:49:56 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:45:32 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
 mapping a transformation over a string.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
#include <stdio.h>

static char	index_char(unsigned int i, char c)
{
	return (i + c+2);
}

int	main()
{
	char	*s = "hellz";
	char	*result;

	result = ft_strmapi(s, index_char);
	if (result)
	{
		printf("%s\n", result);
		printf("original string%s\n", s);
		free(result);
	}
	else
	{
		printf("Memory allocation failed\n");
	}
}
*/