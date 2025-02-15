/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:34:36 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/19 17:23:16 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}
/*
#include <stdio.h>
void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}
int main()
{
t_list	*third = ft_lstnew(ft_strdup("third"));
t_list	*second = ft_lstnew(ft_strdup("second"));
t_list	*first = ft_lstnew(ft_strdup("first"));

first->next = second;
second->next = third;

printf("Initial list:\n");
ft_lstiter(first, print_content);

ft_lstdelone(third, free);
ft_lstdelone(second, free);
ft_lstdelone(first, free);
return (0);
}
*/