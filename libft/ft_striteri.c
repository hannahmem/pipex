/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:05:49 by hmanes-e          #+#    #+#             */
/*   Updated: 2024/10/28 13:12:10 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

void example_function(unsigned int index, char *c) 
{
    if (*c >= 'a' && *c <= 'z') {
        *c = *c - 32;
    }
}

int main() 
{
    char str[] = "hello world!";
    ft_striteri(str, example_function);
    printf("%s\n", str);
    return 0;
}*/