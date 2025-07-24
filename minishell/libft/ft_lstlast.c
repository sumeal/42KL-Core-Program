/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:11:06 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:44:19 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	make the pointer point to the last node of the list
*/
#include "../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	lstnew = (t_list *)malloc(sizeof(t_list));
	if (!lstnew)
		return (NULL);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}

int main(void)
{
	t_list *head = ft_lstnew("First Node");
	t_list *second = ft_lstnew("Second Node");
	t_list *third = ft_lstnew("Third Node");

	head->next = second;
	second->next = third;

	t_list *last = ft_lstlast(head);
	if (last)
		printf("last node: %s\n", (char *)last->content);
	free(head);
	free(second);
	free(third);
	return (0);
}
*/