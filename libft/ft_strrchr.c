/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:20:35 by hmanes-e          #+#    #+#             */
/*   Updated: 2024/10/28 14:22:34 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_len;

	s_len = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[s_len]);
	while (s_len >= 0)
	{
		if (s[s_len] == (char)c)
			return ((char *)&s[s_len]);
		s_len--;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main()
{
	const char *s1 = "Hello bitches";
	char c = 'h';
	char *result = ft_strrchr(s1, c);

	printf("last '%c' found at position %ld\n", c, result - s1);
}*/