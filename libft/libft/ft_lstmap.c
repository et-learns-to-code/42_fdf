/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:27:11 by etien             #+#    #+#             */
/*   Updated: 2024/06/11 17:32:42 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Creates new list applying function.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
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

// Transformation function to convert a string to uppercase
void *transform_to_upper(void *content)
{
    char *str = (char *)content;
    char *result = strdup(str); // Allocate memory for the result string
    if (!result)
        return NULL;
    for (int i = 0; result[i]; i++)
    {
        if (result[i] >= 'a' && result[i] <= 'z')
            result[i] -= 32; // Convert lowercase to uppercase
    }
    return result;
}

int main(void)
{
    // Create a linked list with strings "apple", "banana", and "orange"
    t_list *list = NULL;
    ft_lstadd_back(&list, ft_lstnew(strdup("apple")));
    ft_lstadd_back(&list, ft_lstnew(strdup("banana")));
    ft_lstadd_back(&list, ft_lstnew(strdup("orange")));

    // Print the original list
    printf("Original list:\n");
    ft_lstiter(list, print_content);

    // Apply transformation function to convert each element
	// to uppercase using ft_lstmap
    t_list *mapped_list = ft_lstmap(list, transform_to_upper, free_content);

    // Print the mapped list
    printf("\nMapped list (uppercase):\n");
    ft_lstiter(mapped_list, print_content);

    // Clean up the original and mapped lists
    ft_lstclear(&list, free_content);
    ft_lstclear(&mapped_list, free_content);

    return 0;
}
*/
