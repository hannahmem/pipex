/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:36:02 by hmanes-e          #+#    #+#             */
/*   Updated: 2024/10/23 17:39:19 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n--)
	{
		*temp++ = 0;
	}
}

/*
#include <stdio.h>

int main(void)
{
    char buffer[20];

    ft_memset(buffer, 'A', sizeof(buffer) - 1);
    buffer[19] = '\0';
    printf("Buffer before ft_bzero: %s\n", buffer);
    ft_bzero(buffer, 10);
    printf("Buffer after ft_bzero: ");
    for (int i = 0; i < 20; i++) {
        if (buffer[i] == 0)
            printf("\\0");
        else
            printf("%c", buffer[i]);
    }
    printf("\n");
    return 0;
}*/