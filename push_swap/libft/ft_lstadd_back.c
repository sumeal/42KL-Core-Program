/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:17:12 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/19 19:29:48 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}
/*
#include <stdio.h>

int main(void)
{
	t_list	*one = ft_lstnew("first");
	t_list	*two = ft_lstnew("second");
	t_list	*three = ft_lstnew("third");
	t_list	*temp;

	one->next = two;
	printf("%s\n", (char *)one->content);
	ft_lstadd_back(&one, three);
	temp = one;
	while (temp->content != NULL)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	return (0);
}
*/