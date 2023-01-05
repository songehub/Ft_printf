/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:40:04 by ccrecent          #+#    #+#             */
/*   Updated: 2023/01/05 16:21:21 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar(('-'));
		ft_putchar(('2'));
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar(('-'));
		n = -n;
		ft_putnbr((n));
	}
	else if (n > 9)
	{
		ft_putnbr((n / 10));
		ft_putnbr((n % 10));
	}
	else
		ft_putchar((n + 48));
}
