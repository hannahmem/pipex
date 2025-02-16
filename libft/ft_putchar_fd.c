/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanes-e <hmanes-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:00:44 by hmanes-e          #+#    #+#             */
/*   Updated: 2024/10/22 16:02:42 by hmanes-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	int	written;

	written = write(fd, &c, 1);
	if (written == -1)
		return (-1);
	return (written);
}
