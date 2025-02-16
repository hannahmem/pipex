/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:59:23 by hmanes-e          #+#    #+#             */
/*   Updated: 2024/10/22 14:26:02 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	count;
	int	written;

	count = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		written = ft_putchar_fd(*s++, fd);
		if (written == -1)
			return (-1);
		count += written;
	}
	return (count);
}
/*
int main()
{
	ft_putstr_fd("Hello, bitches\n", 2);
}*/