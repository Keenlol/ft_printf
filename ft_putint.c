/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctongpa <ctongpa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:22:42 by ctongpa           #+#    #+#             */
/*   Updated: 2024/09/29 16:39:34 by ctongpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
