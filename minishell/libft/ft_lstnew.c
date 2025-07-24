/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:11:16 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:44:27 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	crate a new node;
	do not forget free node after using this
*/
#include "../includes/libft.h"

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
/*
#include <stdio.h>

int	main(void)
{
	t_list	*check;
	
	check = ft_lstnew("string");
	printf("content: %s\n", (char *)check->content);
	free(check);
	return (0);
}
*/