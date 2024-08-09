/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:01:23 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:34:10 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// create temp variable to avoid modifying the existing list

// Returns number of list nodes.
int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		size;

	temp = lst;
	size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

/*
#include <stdio.h>

// Main function to test ft_lstsize
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

    // Get the size of the linked list using ft_lstsize
    int size = ft_lstsize(head);
    printf("Size of the linked list: %d\n", size);

    // Free the allocated memory for the nodes
    free(head);
    free(second);
    free(third);

    return 0;
}
*/
