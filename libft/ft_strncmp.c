/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:35:22 by hmanes-e          #+#    #+#             */
/*   Updated: 2024/10/28 13:13:42 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
	char s1[] = "ABCD";
	char s2[] = "Abse";
	size_t n = 4;
	int result = ft_strncmp(s1, s2, n);
	printf("%d\n", result);
	return (0);
}*/