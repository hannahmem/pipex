/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:44:58 by hmanes-e          #+#    #+#             */
/*   Updated: 2024/10/22 16:01:51 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_ptr;

	s_ptr = (const unsigned char *)s;
	while (n--)
	{
		if (*s_ptr == (unsigned char)c)
			return ((void *)s_ptr);
		s_ptr++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main(void)
{
    const char *str = "Hello, World!";
    char ch = 'H';
	size_t n = 13;
    
    char *result = ft_memchr(str, ch, n);
    printf("%c is in %ld\n", ch, (unsigned char*)result - (unsigned char*)str);
    return 0;
}*/