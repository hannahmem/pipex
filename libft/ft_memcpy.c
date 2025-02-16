/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:35:00 by hmanes-e          #+#    #+#             */
/*   Updated: 2024/10/28 14:09:28 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	if (src == NULL && dst == NULL)
		return (NULL);
	dst_ptr = (unsigned char *) dst;
	src_ptr = (unsigned char *) src;
	while (n > 0)
	{
		*(dst_ptr++) = *(src_ptr++);
		n--;
	}
	return (dst);
}
/*
#include <stdio.h>

int main()
{
	char dst[15];
	char src[] = "Mamma mia";
	size_t n = 15;
	void *result = ft_memcpy(dst, src, n);
	printf("%s\n", result);
	return (0);
}*/
