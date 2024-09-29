/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctongpa <ctongpa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:26:43 by ctongpa           #+#    #+#             */
/*   Updated: 2024/09/29 16:33:14 by ctongpa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

int	ft_printf(const char *str, ...);

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_puthex(unsigned int num, char padding);
int	ft_putint(int num);
int	ft_putptr(void *ptr);
int	ft_putunsigned(unsigned int num);
