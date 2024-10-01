/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctongpa <ctongpa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:22:34 by ctongpa           #+#    #+#             */
/*   Updated: 2024/09/29 16:37:42 by ctongpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	puthex_ptr(uintptr_t num)
{
	int	count;

	count = 0;
	if (num < 16)
	{
		if (num < 10)
			count += ft_putchar(num + '0');
		else
			count += ft_putchar(num - 10 + 'a');
		return (count);
	}
	else
		count += puthex_ptr(num / 16);
	count += puthex_ptr(num % 16);
	return (count);
}

int	ft_putptr(void *ptr)
{
	uintptr_t	num;

	if (!ptr)
		return (ft_putstr("(nil)"));
	num = (uintptr_t) ptr;
	return (ft_putstr("0x") + puthex_ptr(num));
}
