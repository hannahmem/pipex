/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:56:15 by hmanes-e          #+#    #+#             */
/*   Updated: 2024/10/28 13:10:16 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*arr;
	long	nb;
	int		len;

	nb = n;
	len = count(nb);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	arr[len] = '\0';
	if (nb == 0)
		arr[0] = '0';
	if (nb < 0)
	{
		arr[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		arr[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (arr);
}
/*
#include <stdio.h>
#include <limits.h>
int main(void) 
{
    int test_cases[] = {0, 42, -42, 123456, -123456, INT_MAX, INT_MIN}; 
    int num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_test_cases; i++) {
        char *result = ft_itoa(test_cases[i]);
        if (result) {
            printf("ft_itoa(%d) = %s\n", test_cases[i], result);
            free(result); // Free the allocated memory
        } else {
            printf("ft_itoa(%d) = NULL (memory allocation failed)\n", 
			test_cases[i]);
        }
    }
    return 0;
}*/