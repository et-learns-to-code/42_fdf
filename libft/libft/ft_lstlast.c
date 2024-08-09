/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:23:00 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:34:01 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns last node of list.
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

/*
#include <stdio.h>

// Main function to test ft_lstlast
int main() {
    // Create a linked list with three nodes
    t_list *head = (t_list *)malloc(sizeof(t_list));
    t_list *second = (t_list *)malloc(sizeof(t_list));
    t_list *third = (t_list *)malloc(sizeof(t_list));

    // Link the nodes together
    head->content = "first";
    head->next = second;
    second->content = "second";
    second->next = third;
    third->content = "third";
    third->next = NULL;

    // Print the linked list
    printf("Linked List: ");
    t_list *temp = head;
    while (temp) {
        printf("%s -> ", (char *)temp->content);
        temp = temp->next;
    }
    printf("NULL\n");

    // Get the last node of the linked list using ft_lstlast
    t_list *last = ft_lstlast(head);
    if (last)
        printf("Last node: %s\n", (char *)last->content);
    else
        printf("The list is empty.\n");

    // Free the allocated memory for the nodes
    free(head);
    free(second);
    free(third);

    return 0;
}
*/
