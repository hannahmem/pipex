/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:04:12 by hmanes-e          #+#    #+#             */
/*   Updated: 2024/10/28 14:46:22 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	total_size;
	void	*ptr;

	if (num == 0 || size == 0)
		return (malloc(0));
	if (num > SIZE_MAX / size)
		return (NULL);
	total_size = num * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
/*
#include <stdio.h>
int main() {
    int *arr = (int *)ft_calloc(5, sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("First element: %d\n", arr[0]);
    free(arr);
    return 0;
}*/