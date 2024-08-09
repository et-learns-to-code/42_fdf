/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:55:43 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:33:23 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Adds node to end of list.
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}

/*
#include <stdio.h>

// Function to print the list content
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
    t_list *list = NULL;
    t_list *elem1 = ft_lstnew("First");
    t_list *elem2 = ft_lstnew("Second");
    t_list *elem3 = ft_lstnew("Third");

    ft_lstadd_back(&list, elem1);
    ft_lstadd_back(&list, elem2);
    ft_lstadd_back(&list, elem3);

    print_list(list);

    // Free the allocated memory
    while (list)
    {
        t_list *tmp = list;
        list = list->next;
        free(tmp);
    }

    return 0;
}
*/
