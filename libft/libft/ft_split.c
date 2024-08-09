/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:17:02 by etien             #+#    #+#             */
/*   Updated: 2024/07/29 11:11:27 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**fill_arr(char const *s, char c, char **arr);
static int	word_count(char const *s, char c);
static void	*free_all(char **arr, int n);
static char	*fill_word(char const *s, int start, int end);

// Splits string into array.
char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	arr = fill_arr(s, c, arr);
	return (arr);
}

// counts number of words in original string by checking for separators
static int	word_count(char const *s, char c)
{
	int	count;
	int	word_marker;

	count = 0;
	word_marker = 0;
	while (*s)
	{
		if (*s != c && word_marker == 0)
		{
			count++;
			word_marker = 1;
		}
		else if (*s == c)
			word_marker = 0;
		s++;
	}
	return (count);
}

// word_start will be passed in as an array index to fill_word function
// It will equal -1 when it is not the start of the word, and equal i
// when a new word is found. To distinguish between these states,
// it cannot equal to 0 because 0 is a valid array index and
// will create confusion. i will continue incrementing until
// a separator is found, then the word will be stored in the array
// by calling fill_word.

// function detects start of word by checking that char is not a separator
// and word start marker is off (it will then be switched on); end of word
// is detected when i index is either a separator or the end of the entire
// string when end of word is detected, the entire word is stored in an
// array then the word marker is switched off again
static char	**fill_arr(char const *s, char c, char **arr)
{
	size_t	i;
	int		j;
	int		word_start;

	i = 0;
	j = 0;
	word_start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && word_start < 0)
			word_start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && word_start >= 0)
		{
			arr[j] = fill_word(s, word_start, i);
			if (!arr[j])
				return (free_all(arr, j));
			word_start = -1;
			j++;
		}
		i++;
	}
	return (arr);
}

// allocates memory for individual words within strings array
// string is created from start index until (end - 1);
// i.e. end char is excluded from the string
static char	*fill_word(char const *s, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)ft_calloc(end - start + 1, sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i++] = s[start++];
	}
	return (word);
}

// completely clears all previously assigned memory if any one string
// fails to have memory allocated
static void	*free_all(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

/*
#include <stdio.h>

void print_split_result(char **result) {
    int i = 0;
    while (result[i] != NULL) {
        printf("result[%d]: %s\n", i, result[i]);
        i++;
    }
}

int main() {
    char *s1 = "hello world this is a test";
    char *s2 = "   leading and trailing spaces   ";
    char *s3 = "no-separators";
    char *s4 = "multiple   spaces   between   words";
    char *s5 = ""; // empty string
    char *s6 = "ababaaaMy name is Simonbbaaabbad";
    char **result;

    printf("Testing ft_split with different inputs:\n");

    printf("\nInput: \"%s\", Separator: ' '\n", s1);
    result = ft_split(s1, ' ');
    print_split_result(result);
    // Free memory allocated by ft_split
    for (int i = 0; result[i] != NULL; i++) {
        free(result[i]);
    }
    free(result);

    printf("\nInput: \"%s\", Separator: ' '\n", s2);
    result = ft_split(s2, ' ');
    print_split_result(result);
    // Free memory allocated by ft_split
    for (int i = 0; result[i] != NULL; i++) {
        free(result[i]);
    }
    free(result);

    printf("\nInput: \"%s\", Separator: '-'\n", s3);
    result = ft_split(s3, '-');
    print_split_result(result);
    // Free memory allocated by ft_split
    for (int i = 0; result[i] != NULL; i++) {
        free(result[i]);
    }
    free(result);

    printf("\nInput: \"%s\", Separator: ' '\n", s4);
    result = ft_split(s4, ' ');
    print_split_result(result);
    // Free memory allocated by ft_split
    for (int i = 0; result[i] != NULL; i++) {
        free(result[i]);
    }
    free(result);

    printf("\nInput: \"%s\", Separator: ' '\n", s5);
    result = ft_split(s5, ' ');
    print_split_result(result);
    // Free memory allocated by ft_split
    for (int i = 0; result[i] != NULL; i++) {
        free(result[i]);
    }
    free(result);

    printf("\nInput: \"%s\", Separator: ' '\n", s6);
    result = ft_split(s6, ' ');
    print_split_result(result);
    // Free memory allocated by ft_split
    for (int i = 0; result[i] != NULL; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
*/
