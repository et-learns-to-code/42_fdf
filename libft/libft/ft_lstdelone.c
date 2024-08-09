/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:16:57 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:31:54 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// deletes a given node from the list - lst is the node to be deleted
// only content is freed; if next is freed,
// that would mean deleting the next node

// Deletes single node from list.
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
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

// Custom delete function for list content
void del(void *content)
{
    // Assuming content is a dynamically allocated string
    free(content);
}

int main(void)
{
    t_list *list = NULL;
    t_list *elem1 = ft_lstnew(strdup("First"));
    t_list *elem2 = ft_lstnew(strdup("Second"));
    t_list *elem3 = ft_lstnew(strdup("Third"));

    elem1->next = elem2;
    elem2->next = elem3;
    list = elem1;

    // Print the list before deletion
    printf("List before deletion:\n");
    print_list(list);

    // Delete the second element
    ft_lstdelone(elem2, del);

    // Manually adjust the link of the previous node to skip the deleted node
    elem1->next = elem3;

    // Print the list after deletion
    printf("List after deletion of the second element:\n");
    print_list(list);

    // Free the remaining elements
    ft_lstdelone(elem1, del);
    ft_lstdelone(elem3, del);

    return 0;
}
*/
