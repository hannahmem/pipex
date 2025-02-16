/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:54:11 by hmanes-e          #+#    #+#             */
/*   Updated: 2024/10/28 15:43:01 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = c;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i++;
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
    const char *str = "Hello, World!";
    char ch = 'W';
    
    char *result = ft_strchr(str, ch);
    printf("%c is in %ld\n", ch, result - str);
    return 0;
}*/