/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:14:06 by hmanes-e          #+#    #+#             */
/*   Updated: 2024/10/16 11:31:02 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *)b;
	while (len--)
	{
		*(temp++) = (unsigned char) c;
	}
	return (b);
}
/*
#include <stdio.h>

int main(void)
{
    char buffer[20];

    ft_memset(buffer, '-', sizeof(buffer) - 1);
    buffer[19] = '\0';
    printf("Buffer before memset: %s\n", buffer);
    ft_memset(buffer, 'A', 10);
    printf("Buffer after memset:  %s\n", buffer);
    return 0;
}*/