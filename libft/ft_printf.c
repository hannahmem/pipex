/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:50:09 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 09:50:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_elements(char placeholders, va_list args)
{
	int	count;

	count = 0;
	if (placeholders == 'd' || placeholders == 'i')
		count = ft_putnbr_fd(va_arg(args, int), 1);
	else if (placeholders == 'c')
		count = ft_putchar_fd((char)va_arg(args, int), 1);
	else if (placeholders == 's')
		count = ft_putstr_fd(va_arg(args, char *), 1);
	else if (placeholders == 'p')
		count = ft_print_ptr(va_arg(args, unsigned long long), 1);
	else if (placeholders == 'u')
		count = ft_putnbr_uns_fd(va_arg(args, unsigned int), 1);
	else if (placeholders == 'x' || placeholders == 'X')
		count = ft_print_hex(placeholders, args, 1);
	else if (placeholders == '%')
		count = write(1, "%", 1);
	else
		count = write(1, &placeholders, 1);
	if (count == -1)
		return (-1);
	return (count);
}

static int	errors_handling(int written, va_list args)
{
	if (written == -1)
	{
		va_end(args);
		return (-1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	count;
	int		written;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			written = ft_print_elements(format[i], args);
		}
		else
			written = write(1, &format[i], 1);
		if (errors_handling(written, args))
			return (-1);
		count += written;
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>
// int main(void) {
// 	// ft_printf("%d %i %c %s %% %x %X %u\n", 25, 36, 'a', 
// "Hello", 255, 255, 3);
// 	// char	*x = "Oh yeah";
// 	// ft_printf("%p\n", &x);
// 	char	*s = "coucoutest";
// 	//void	*p = s;

// 	ft_printf("MY: %p\n", s);
// 	printf("TY: %p\n", s);
// //	printf("ft_printf = %d ", ft_printf("%p\n", p));

// 	//printf("\n");
// 	//printf("printf = %d ", printf("%p\n", s));
// //	printf("printf = %d ", printf("%p\n", p));
// 	return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     int count;

//     printf("\n=== Integer Tests ===\n");
//     count = ft_printf("Integer (positive): %d\n", 42);
//     count = printf("Integer (positive): %d\n", 42);
//     printf("[Expected 23] Printed %d characters.\n\n", count);

//     count = ft_printf("Integer (negative): %i\n", -42);
//     count = printf("Integer (negative): %i\n", -42);
//     printf("[Expected 24] Printed %d characters.\n\n", count);

//     printf("\n=== Character Tests ===\n");
//     count = ft_printf("Character: %c\n", 'A');
//     count = printf("Character: %c\n", 'A');
//     printf("[Expected 13] Printed %d characters.\n\n", count);

//     printf("\n=== String Tests ===\n");
//     count = ft_printf("String: %s\n", "Hello, world!");
//     count = printf("String: %s\n", "Hello, world!");
//     printf("[Expected 22] Printed %d characters.\n\n", count);

//     count = ft_printf("NULL String: %s\n", NULL);
//     count = printf("NULL String: %s\n", NULL);
//     printf("[Expected 20] Printed %d characters.\n\n", count);

//     count = ft_printf("Empty String: %s\n", "");
//     count = printf("Empty String: %s\n", "");
//     printf("[Expected 15] Printed %d characters.\n\n", count);

//     printf("\n=== Pointer Tests ===\n");
//     int *ptr = malloc(sizeof(int));
//     if (ptr)
//     {
//         *ptr = 100;
//         count = ft_printf("Pointer: %p\n", ptr);
//         count = printf("Pointer: %p\n", ptr);
//         printf("[Expected 20] Printed %d characters.\n\n", count);
//         free(ptr);
//     }
//     else
//     {
//         printf("Memory allocation failed.\n");
//     }

//     printf("\n=== Unsigned Integer Tests ===\n");
//     count = ft_printf("Unsigned Integer: %u\n", 42);
//     count = printf("Unsigned Integer: %u\n", 42);
//     printf("[Expected 21] Printed %d characters.\n\n", count);

//     printf("\n=== Hexadecimal Tests ===\n");
//     count = ft_printf("Hexadecimal (lowercase): %x\n", 255);
//     count = printf("Hexadecimal (lowercase): %x\n", 255);
//     printf("[Expected 28] Printed %d characters.\n\n", count);

//     count = ft_printf("Hexadecimal (uppercase): %X\n", 255);
//     count = printf("Hexadecimal (uppercase): %X\n", 255);
//     printf("[Expected 28] Printed %d characters.\n\n", count);

//     printf("\n=== Special Character Tests ===\n");
//     count = ft_printf("Percent Sign: %%\n");
//     count = printf("Percent Sign: %%\n");
//     printf("[Expected 16] Printed %d characters.\n\n", count);

//     return 0;
// }

// #include <fcntl.h> // For invalid file descriptor testing

// int main(void)
// {
//     // Valid case
//     ft_printf("Valid test: %s, %d, %p\n", "test", 42, (void *)42);

//     // Invalid file descriptor
//     int invalid_fd = -1;
//     int result = ft_putchar_fd('A', invalid_fd);
//     ft_printf("Invalid FD test, ft_putchar_fd: %d\n", result);

//     // Error propagation in ft_printf
//     int error_test = ft_printf("Invalid test with %%c\n", invalid_fd);
//     if (error_test == -1)
//         ft_printf("ft_printf correctly returned -1 for error.\n");

//     return 0;
// }

// int main(void) {
// 	printf("%d\n", printf("%p\n", NULL));
// 	printf("%d\n", ft_printf("%p\n", NULL));
// 	return 0;
// }