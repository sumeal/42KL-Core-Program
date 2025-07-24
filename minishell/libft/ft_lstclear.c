/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:02:33 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:44:12 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	clear a list;
	del func: delete the content
*/
#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*copyptr;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		copyptr = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = copyptr;
	}
	*lst = NULL;
}
/*
#include <stdio.h>

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

void	del(void *content)
{
	printf("free content: %s\n", (char *)content);
	free(content);
}

int	main(void)
{
	char	*content = malloc(12);
	if (!content)
		return (1);
	sprintf(content, "hello world");

	t_list	*head = ft_lstnew(content);
	ft_lstclear(&head, &del);

	return (0);
}
*/