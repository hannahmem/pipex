/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:15:47 by hmanes-e          #+#    #+#             */
/*   Updated: 2024/10/16 14:21:22 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	if (!src && !dst)
		return (NULL);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (const unsigned char *)src;
	i = 0;
	if (dst_ptr > src_ptr)
	{
		while (len--)
			dst_ptr[len] = src_ptr[len];
	}
	else
	{
		while (i < len)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char src1[20] = "Hello, World!";
    char dest1[20];

    char src2[20] = "Overlap test";
    char *dest2 = src2 + 5;  // Creating overlap

    // Case 1: Non-overlapping memory regions
    printf("Before memmove (non-overlapping):\n");
    printf("src1: %s\n", src1);
    printf("dest1 (empty): %s\n", dest1);

    ft_memmove(dest1, src1, strlen(src1) + 1);  // +1 to include null terminator

    printf("After memmove (non-overlapping):\n");
    printf("src1: %s\n", src1);
    printf("dest1: %s\n", dest1);
    printf("\n");

    // Case 2: Overlapping memory regions
    printf("Before memmove (overlapping):\n");
    printf("src2: %s\n", src2);
    printf("dest2 (overlap at src2 + 5): %s\n", dest2);

    ft_memmove(dest2, src2, strlen(src2));  // Overlap region

    printf("After memmove (overlapping):\n");
    printf("src2: %s\n", src2);
    printf("dest2: %s\n", dest2);
    printf("\n");

    return 0;
}*/