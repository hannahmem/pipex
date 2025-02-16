/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:05:44 by hmanes-e          #+#    #+#             */
/*   Updated: 2024/10/28 13:20:51 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	count;
	int	wfound;

	count = 0;
	wfound = 0;
	while (*s)
	{
		if (*s != c && !wfound)
		{
			wfound = 1;
			count++;
		}
		else if (*s == c)
		{
			wfound = 0;
		}
		s++;
	}
	return (count);
}

static char	*allocate_word(const char *start, const char *end)
{
	char	*word;
	int		i;

	word = (char *)malloc(end - start + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i++] = *start++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_memory(char **arr, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**ft_split2(const char *s, char c, char **arr)
{
	int			i;
	const char	*start;
	const char	*end;

	i = 0;
	start = NULL;
	while (*s)
	{
		if (*s != c && !start)
			start = s;
		if ((*s == c || *(s + 1) == '\0') && start)
		{
			end = s;
			if (*(s + 1) == '\0' && *s != c)
				end = s + 1;
			arr[i] = allocate_word(start, end);
			if (!arr[i])
				return (free_memory(arr, i), NULL);
			i++;
			start = NULL;
		}
		s++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	int		words_count;
	char	**arr;

	if (!s)
		return (NULL);
	words_count = word_count(s, c);
	arr = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!ft_split2(s, c, arr))
		return (NULL);
	return (arr);
}
/*
#include <stdio.h>
// int main(void)
// {
// 	int n = 3;
// 	char **result = ft_split("Hello World!", 'o');
// 	while (n--)
// 		printf("%s\n", result[n]);
// 	return (0);
// }

void	print_split_result(char **result)
{
	if (!result)
	{
		printf("NULL\n");
		return;
	}
	for (int i = 0; result[i]; i++)
	{
		printf("Word %d: \"%s\"\n", i, result[i]);
		free(result[i]); // Free each word after printing
	}
	free(result); // Free the array of words itself
}

int	main(void)
{
	char **result;

	printf("Test 1: Basic split\n");
	result = ft_split("hello world this is a test", ' ');
	print_split_result(result);

	printf("\nTest 2: Consecutive delimiters\n");
	result = ft_split("hello,,world,,this,is,a,test", ',');
	print_split_result(result);

	printf("\nTest 3: Delimiter at start and end\n");
	result = ft_split(",hello,world,", ',');
	print_split_result(result);

	printf("\nTest 4: Empty string\n");
	result = ft_split("", ',');
	print_split_result(result);

	printf("\nTest 5: Only delimiters\n");
	result = ft_split(",,,,,", ',');
	print_split_result(result);

	printf("\nTest 6: No delimiters\n");
	result = ft_split("hello", ',');
	print_split_result(result);

	printf("\nTest 7: Multiple spaces as delimiters\n");
	result = ft_split("   hello   world  ", ' ');
	print_split_result(result);

	printf("\nTest 8: One character string\n");
	result = ft_split("a", ',');
	print_split_result(result);

	printf("\nTest 9: Delimiter is a space\n");
	result = ft_split("word1 word2 word3", ' ');
	print_split_result(result);

	printf("\nTest 10: Long string with mixed delimiters\n");
	result = ft_split("hello,, world! test ! split", '!');
	print_split_result(result);

	return 0;
}*/