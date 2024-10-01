/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctongpa <ctongpa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:49:21 by ctongpa           #+#    #+#             */
/*   Updated: 2024/09/29 16:39:34 by ctongpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(const char *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	conversion(char c, va_list args)
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
		count += ft_putptr(va_arg(args, void *));
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
			if (check("%%cspuiduxX", *str))
				final_count += conversion(*str, args);
			else
				return (-1);
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
