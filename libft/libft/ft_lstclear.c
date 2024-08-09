/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:39:06 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:32:10 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deletes all nodes from list.
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}

/*
#include <stdio.h>

void del(void *content)
{
    free(content);
}

void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main(void)
{
    t_list *list = ft_lstnew(strdup("First"));
    list->next = ft_lstnew(strdup("Second"));
    list->next->next = ft_lstnew(strdup("Third"));

    printf("List before clearing:\n");
    print_list(list);

    ft_lstclear(&list, del);

    printf("List after clearing:\n");
    print_list(list);

    return 0;
}
*/
