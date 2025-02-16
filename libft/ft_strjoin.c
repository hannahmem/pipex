/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:42:27 by hmanes-e          #+#    #+#             */
/*   Updated: 2025/01/22 12:54:42 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat1(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	str[0] = '\0';
	ft_strcat1(str, s1);
	ft_strcat1(str, s2);
	return (str);
}
/*
#include <stdio.h>
int main() {
	char *s1 = "Hello";
	char *s2 = "World";
	char *result = (ft_strjoin(s1, s2));
	printf("%s\n", result);
	free(result);
	return (0);
}*/