/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:04:49 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:45:11 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 duplicate a string by allocating memory for a copy of the original string and
  then copying the characters to the newly allocated memory. 
*/
#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	arr = (char *)malloc(i + 1);
	if (!arr)
		return (NULL);
	while (j < i)
	{
		arr[j] = s[j];
		j++;
	}
	arr[i] = '\0';
	return (arr);
}
/*
int main(void)
{
	// test empty string
	const char *empty_str = "";
	char *dup_empty = ft_strdup(empty_str);
	printf("Original: '%s', Duplicate: '%s'\n", empty_str, dup_empty);
	free(dup_empty);

	// test normal string
 	const char *str = "Hello, World!";
	char *dup_str = ft_strdup(str);
	printf("Original: '%s', Duplicate: '%s'\n", str, dup_str);
	free(dup_str);

	// test the string is null
	const char *null_str = NULL;
	char *dup_null = ft_strdup(null_str);
	if (dup_null == NULL)
		printf("Original: (null), Duplicate: (null)\n");

	return 0;
}
*/