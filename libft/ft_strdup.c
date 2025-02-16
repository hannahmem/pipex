/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:40:32 by hmanes-e          #+#    #+#             */
/*   Updated: 2025/01/22 12:53:53 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy1(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = malloc(ft_strlen(s1) + 1);
	if (copy == NULL)
		return (NULL);
	ft_strcpy1(copy, s1);
	return (copy);
}
/*
#include <stdio.h>
int main()
{
	char original[] = "Mamma mia";
	char *duplicate = ft_strdup(original);
	if (duplicate != NULL)
	{
		printf("Original: %s\n", original);
		printf("Duplicate: %s\n", duplicate);
		free(duplicate);
	}
	else
		printf("Memory allocation failed.\n");
	return (0);
}*/