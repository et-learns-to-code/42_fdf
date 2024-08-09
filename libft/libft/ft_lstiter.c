/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:02:31 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:32:22 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates through list, applying function.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst-> next;
	}
}

/*
#include <stdio.h>

// Function to print the content of each list node
void print_content(void *content)
{
    printf("%s\n", (char *)content);
}

// Function to free the content of each list node
void free_content(void *content)
{
    free(content);
}

int main(void)
{
    // Create an empty linked list
    t_list *list = NULL;
    // Add nodes containing strings "First", "Second",
	// and "Third" to the back of the list
    ft_lstadd_back(&list, ft_lstnew(strdup("First")));
    ft_lstadd_back(&list, ft_lstnew(strdup("Second")));
    ft_lstadd_back(&list, ft_lstnew(strdup("Third")));

    // Print the content of each node using ft_lstiter
    printf("Printing list contents:\n");
    ft_lstiter(list, print_content);

    // Clean up the list
    ft_lstclear(&list, free_content);

    return 0;
}
*/
