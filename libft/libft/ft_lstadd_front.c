/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:53:50 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:30:59 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// lst points to the head of the list, by dereferencing it,
// it will get the current first node on the list.
// the second line updates the head of the list to the new node.

// Adds node to beginning of list.
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
#include <stdio.h>

// Helper function to print the list
void ft_lstprint(t_list *lst) {
    while (lst) {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

// Main function to test ft_lstadd_front
int main() {
    // Create initial list nodes using static string literals
    t_list *head = ft_lstnew("second");
    t_list *new_node = ft_lstnew("first");

    // Print the memory addresses of the nodes
    printf("head node address: %p\n", (void*)head);
    printf("new_node address: %p\n", (void*)new_node);

    // Print initial list
    printf("Initial list: ");
    ft_lstprint(head);

    // Add new_node to the front of the list
    ft_lstadd_front(&head, new_node);

    // Print updated list
    printf("Updated list: ");
    ft_lstprint(head);

    // Free the allocated memory for the nodes
    // (Ensure to free all dynamically allocated memory)
    t_list *current = head;
    while (current) {
        t_list *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
*/
