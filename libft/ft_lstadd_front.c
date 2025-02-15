/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:41:00 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/12 09:43:23 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>

int main(void)
{
	t_list	*one = ft_lstnew("first");
	t_list	*two = ft_lstnew("second");
	t_list	*temp;

	printf("%s\n", (char *)one->content);
	ft_lstadd_front(&one, two);
	temp = one;
	while (temp->content != NULL)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	return (0);
}
*/