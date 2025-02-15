/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:21:28 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/19 19:30:55 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	free(*lst);
}
/*
#include <stdio.h>
// Custom function to free content 
void free_content(void *content)
 { free(content); } 
 // Function to print the list 
 void print_list(t_list *lst) 
 { while (lst) 
 	{ 	
		printf("%s -> ", (char *)lst->content); 
		lst = lst->next; 
	} 
	printf("NULL\n"); } 
 int main(void) 
 { // Create initial list with three elements 
 t_list *third = ft_lstnew(ft_strdup("third")); 
 t_list *second = ft_lstnew(ft_strdup("second")); 
 t_list *first = ft_lstnew(ft_strdup("first")); 
 first->next = second; 
 second->next = third; printf("Initial list:\n"); 
 print_list(first); 
 // Clear the list using ft_lstclear 
 ft_lstclear(&first, free_content); 
 printf("List after clearing:\n"); 
 print_list(first); 
 // Should print "NULL" 
 return 0; 
 }
*/