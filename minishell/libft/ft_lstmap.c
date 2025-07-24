/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:25:02 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:44:24 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	create a new list pointer.
	using function f to change the content of original list;
	put the content to new list;
	if memory allocation failure, clear that memory, return null
*/
#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*node;

	newlst = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&node, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, node);
		lst = lst->next;
	}
	return (newlst);
}
/*
#include <stdlib.h>
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

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

// Function to double the integer content in each node (example transformation)
void	*double_content(void *content)
{
	int	*new_content = malloc(sizeof(int));
	if (new_content)
		*new_content = (*(int *)content) * 2;
	return (new_content);
}

// Function to free the integer content in a node
void	delete_content(void *content)
{
	free(content);
}

int	main(void)
{
	// Create the original list with integer content
	t_list *head = ft_lstnew(malloc(sizeof(int)));
	t_list *node2 = ft_lstnew(malloc(sizeof(int)));
	t_list *node3 = ft_lstnew(malloc(sizeof(int)));

	if (!head || !node2 || !node3)
		return (1);

	*(int *)(head->content) = 10;
	*(int *)(node2->content) = 20;
	*(int *)(node3->content) = 30;

	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);

	// Apply `ft_lstmap` to double each node's content
	t_list *new_list = ft_lstmap(head, double_content, delete_content);

	// Print the original and the new list
	t_list *current = head;
	printf("Original list:\n");
	while (current)
	{
		printf("%d\n", *(int *)current->content);
		current = current->next;
	}

	current = new_list;
	printf("New list with doubled values:\n");
	while (current)
	{
		printf("%d\n", *(int *)current->content);
		current = current->next;
	}

	// Free both lists
	ft_lstclear(&head, delete_content);
	ft_lstclear(&new_list, delete_content);
	return (0);
}
*/