/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctongpa <ctongpa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:49:21 by ctongpa           #+#    #+#             */
/*   Updated: 2024/09/29 15:48:45 by ctongpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putaddress(void *thing);
// {
// 	return (ft_putstr((char *) &thing));
// }


int	ft_putint(int num)
{
	int	count;

	count = 0;
	if (num == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	if (num < 0)
	{
		count += ft_putchar('-');
		num *= -1;
	}
	if (num < 10)
	{
		count += ft_putchar(num + '0');
		return (count);
	}
	else
		count += ft_putint(num / 10);
	count += ft_putint(num % 10);
	return (count);
}

int	ft_putunsigned(unsigned int num)
{
	int	count;

	count = 0;
	if (num < 10)
		return (ft_putchar(num + '0'));
	else
		count += ft_putunsigned(num / 10);
	count += ft_putunsigned(num % 10);
	return (count);
}

int	ft_puthex(unsigned int num, char padding)
{
	int	count;

	count = 0;
	if (num < 16)
	{
		if (num < 10)
			count += ft_putchar(num + '0');
		else
			count += ft_putchar(num - 10 + padding);
		return (count);
	}
	else
		count += ft_puthex(num / 16, padding);
	count += ft_puthex(num % 16, padding);
	return (count);
}

// _________________________________________

int	conversion(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == '%')
		count += ft_putchar('%');
	else if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count += ft_putaddress(va_arg(args, void *));
	else if (c == 'i' || c == 'd')
		count += ft_putint(va_arg(args, int));
	else if (c == 'u')
		count += ft_putunsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_puthex(va_arg(args, int), 'a');
	else if (c == 'X')
		count += ft_puthex(va_arg(args, int), 'A');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		final_count;
	va_list	args;

	if (!str)
		return (-1);
	va_start(args, str);
	final_count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			final_count += conversion(*str, args);
		}
		else
		{
			final_count += ft_putchar(*str);
		}
		str++;
	}
	va_end(args);
	return (final_count);
}

#include <stdio.h>


int main(void)
{
	ft_printf("| return : %i",ft_printf("hex : %x %X", 255, 255));
}
