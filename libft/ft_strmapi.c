/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:05:54 by hmanes-e          #+#    #+#             */
/*   Updated: 2024/10/28 13:13:04 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	unsigned int		len;
	char				*res;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>

char example_function(unsigned int index, char c) 
{
    if (c >= 'a' && c <= 'z') 
	{
    	return (c - 32);
    }
	return c;
}

int main() 
{
    const char *input_str = "hello world!";
    char *result;

    result = ft_strmapi(input_str, example_function);
	printf("%s\n", result);
	free(result);
}*/