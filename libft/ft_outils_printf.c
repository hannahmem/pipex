/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:53:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 09:53:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_fd(unsigned long long n, char *base, int fd)
{
	int	count;
	int	written;

	count = 0;
	if (n >= 16)
	{
		written = ft_putnbr_base_fd(n / 16, base, fd);
		if (written == -1)
			return (-1);
		count += written;
	}
	written = ft_putchar_fd(base[n % 16], fd);
	if (written == -1)
		return (-1);
	count += written;
	return (count);
}

int	ft_print_ptr(unsigned long long ptr, int fd)
{
	unsigned long long	address;
	int					count;

	address = ptr;
	count = 0;
	count += ft_putstr_fd("0x", fd);
	count += ft_putnbr_base_fd(address, "0123456789abcdef", fd);
	return (count);
}

int	ft_print_hex(char format, va_list args, int fd)
{
	unsigned int	x;
	int				count;

	count = 0;
	x = va_arg(args, unsigned int);
	if (format == 'x')
		count = ft_putnbr_base_fd(x, "0123456789abcdef", fd);
	else
		count = ft_putnbr_base_fd(x, "0123456789ABCDEF", fd);
	return (count);
}

int	ft_putnbr_uns_fd(unsigned int n, unsigned int fd)
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
