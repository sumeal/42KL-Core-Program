/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:48:27 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:44:58 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	1.len_substr: calculate the len of substr using two pointer;
	2.num_substr: count the  number of substrings
	3.set_value: assign a value to each substring
	4.set_str_mem: set the memory for each substring
	5.ft_split: splict string using c
*/
#include "../includes/libft.h"

static int	len_substr(char const *ptr1, char const *ptr2)
{
	int	len;

	len = 0;
	while (ptr2 != ptr1)
	{
		len++;
		ptr2++;
	}
	return (len);
}

static int	num_substr(char const *s, char c)
{
	char const	*ptr1;
	char const	*ptr2;
	int			len;
	int			num;

	ptr1 = s;
	ptr2 = ptr1;
	len = 0;
	num = 0;
	while (*ptr1)
	{
		if (*ptr1 == c)
		{
			len = len_substr(ptr1, ptr2);
			ptr2 = ptr1 + 1;
			if (len > 0)
				num++;
		}
		ptr1++;
	}
	if (len_substr(ptr1, ptr2) > 0)
		num++;
	return (num);
}

static char	*set_value(char **arr, char *ptr2, int len, int num)
{
	char	*str;
	int		j;

	str = (char *)malloc((len + 1));
	if (!str)
	{
		while (num > 0)
			free(arr[--num]);
		free (arr);
		return (NULL);
	}
	j = 0;
	while (j < len)
	{
		str[j] = ptr2[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

static char	**set_str_mem(char const *s, char c, char **arr)
{
	char	*ptr1;
	char	*ptr2;
	int		i;

	ptr1 = (char *) s;
	ptr2 = ptr1;
	i = 0;
	while (*ptr1)
	{
		if (*ptr1 == c)
		{
			if (len_substr(ptr1, ptr2) > 0)
			{
				arr[i] = set_value(arr, ptr2, len_substr(ptr1, ptr2), i);
				i++;
			}
			ptr2 = ptr1 + 1;
		}
		ptr1++;
	}
	if (len_substr(ptr1, ptr2) > 0)
		arr[i] = set_value(arr, ptr2, len_substr(ptr1, ptr2), i);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		num;
	char	**arr;

	if (s == NULL)
		return (NULL);
	num = num_substr(s, c);
	arr = (char **)malloc((num + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = set_str_mem(s, c, arr);
	arr[num] = NULL;
	return (arr);
}
/*
#include <stdio.h>

int main(void)
{
    char *str = "--Hello--world--";
    char delimiter = '-';
    char **result;
    int i = 0;

    // Call ft_split to split the string by the delimiter
    result = ft_split(str, delimiter);

    if (result)
    {
        // Print the split substrings
        while (result[i])
        {
            printf("Substring %d: %s\n", i + 1, result[i]);
            free(result[i]);  // Free each substring after printing
            i++;
        }
        free(result);  // Free the array of string pointers
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
*/