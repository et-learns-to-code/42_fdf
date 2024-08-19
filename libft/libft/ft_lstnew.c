/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:32:07 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:30:44 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Creates new list node.
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*
#include <stdio.h>

int main() {
    // Test content
    int *data = malloc(sizeof(int));
    *data = 42;

    // Create a new list node
    t_list *node = ft_lstnew(data);

    // Check if the node was created successfully
    if (node) {
        printf("Node created successfully.\n");
        printf("Content of the node: %d\n", *(int *)(node->content));
        free(node->content); // Free the content allocated in main
        free(node); // Free the node
    } else {
        printf("Failed to create node.\n");
    }

    return 0;
}
*/
