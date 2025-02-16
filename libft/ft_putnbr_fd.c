/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:01:14 by hmanes-e          #+#    #+#             */
/*   Updated: 2024/10/22 14:26:40 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		count;

	num = n;
	count = 0;
	if (num < 0)
	{
		count += ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num > 9)
		count += ft_putnbr_fd(num / 10, fd);
	count += ft_putchar_fd((num % 10) + '0', fd);
	return (count);
}
/*
int main()
{
	ft_putnbr_fd(-4442, 1);
}*/