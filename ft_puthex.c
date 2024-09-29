/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctongpa <ctongpa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:22:40 by ctongpa           #+#    #+#             */
/*   Updated: 2024/09/29 16:29:00 by ctongpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
