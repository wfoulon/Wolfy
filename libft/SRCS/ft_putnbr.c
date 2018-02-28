/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:54:08 by wfoulon           #+#    #+#             */
/*   Updated: 2017/11/07 18:00:06 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long num;

	num = n;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + '0');
}
