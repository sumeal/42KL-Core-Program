/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:00:10 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:45:43 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. check if s1[i] is in set[j] from the begining of s1
2.checks if each character from the end of s1 is in set
3. copty the trimmed one
*/
#include "../includes/libft.h"

static char	*check_start(char const *s1, char const *set)
{
	char const	*ptr1;
	char const	*ptr2;

	ptr1 = s1;
	while (*ptr1)
	{
		ptr2 = set;
		while (*ptr2 && *ptr1 != *ptr2)
			ptr2++;
		if (*ptr2 == '\0')
			return ((char *)ptr1);
		ptr1++;
	}
	return ((char *)ptr1);
}

static char	*check_end(char const *s1, char const *set)
{
	int			count;
	char const	*ptr1;
	char const	*ptr2;

	ptr1 = s1;
	count = 0;
	while (*ptr1)
	{
		count++;
		ptr1++;
	}
	while (count--)
	{
		ptr1--;
		ptr2 = set;
		while (*ptr2 && *ptr1 != *ptr2)
			ptr2++;
		if (*ptr2 == '\0')
			return ((char *)ptr1);
	}
	return ((char *)ptr1);
}

static void	trimstr_copy(char *s1_trim, char *s1_start, char *s1_end)
{
	char	*trim_copy;

	trim_copy = s1_trim;
	while (s1_start <= s1_end)
	{
		*trim_copy = *s1_start;
		s1_start++;
		trim_copy++;
	}
	*trim_copy = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_trim;
	char	*s1_start;
	char	*s1_end;
	int		count;

	if (s1 == NULL || set == NULL)
		return (NULL);
	s1_start = check_start(s1, set);
	s1_end = check_end(s1, set);
	if (s1_start >= s1_end)
	{
		s1_trim = (char *)malloc(1);
		if (s1_trim)
			s1_trim[0] = '\0';
		return (s1_trim);
	}
	count = s1_end - s1_start + 1;
	s1_trim = (char *)malloc(count + 1);
	if (!s1_trim)
		return (NULL);
	trimstr_copy(s1_trim, s1_start, s1_end);
	return (s1_trim);
}
/*
#include <stdio.h>

int main()
{
    // 1. basic input test
    const char *s1 = "   Hello World!   ";
    const char *set = " ";
    char *result = ft_strtrim(s1, set);
    printf("Trimmed result: '%s'\n", result);
    free(result);

    // test with full blank
    const char *s2 = "     ";
    char *result2 = ft_strtrim(s2, set);
    printf("Trimmed result: '%s'\n", result2);
    free(result2);

    // test with no blank in set
    const char *set2 = "aeiou";
    const char *s3 = "aeHello World!ie";
    char *result3 = ft_strtrim(s3, set2);
    printf("Trimmed result: '%s'\n", result3);
    free(result3);

    // test with nothing needed to be trimmed 
    const char *s4 = "Hello World!";
    const char *set3 = "xyz";
    char *result4 = ft_strtrim(s4, set3);
    printf("Trimmed result: '%s'\n", result4);
    free(result4);
    const char *s5 = "";
    char *result5 = ft_strtrim(s5, set);
    printf("Trimmed result: '%s'\n", result5);
    free(result5);

    const char *s6 = "Hello World!";
    const char *set4 = "";
    char *result6 = ft_strtrim(s6, set4);
    printf("Trimmed result: '%s'\n", result6);
    free(result6);
    return 0;
}
*/