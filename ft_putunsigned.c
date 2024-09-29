/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctongpa <ctongpa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:22:47 by ctongpa           #+#    #+#             */
/*   Updated: 2024/09/29 16:39:32 by ctongpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
