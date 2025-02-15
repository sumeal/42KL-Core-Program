/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:19:43 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/19 19:31:57 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
/*
void	free_content(void *content)
{
	free(content);
}
#include <stdio.h>
void	print_list(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
}
int main(void)
{
	t_list	*list = ft_lstnew(ft_strdup("second"));
	t_list	*first = ft_lstnew(ft_strdup("first"));

	first->next = list;
	print_list(first);
	ft_lstdelone(first, &free_content);
	print_list(list);
	return (0);
}
*/