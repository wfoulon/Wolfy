/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:33:57 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/04 15:33:59 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		hexa_to_int(char c)
{
	if (c > 47 && c < 59)
		return (c - 48);
	if (c > 96 && c < 103)
		return (c - 87);
	if (c > 64 && c < 71)
		return (c - 55);
	return (-1);
}

int		max_power(char *str, int base)
{
	int		n;
	int		result;

	n = ft_strlen(str) - 1;
	if (str[0] == '-')
		n--;
	result = 1;
	while (n > 0)
	{
		result = result * base;
		n--;
	}
	return (result);
}

int		ft_atoi_base(char *str, int base)
{
	int		i;
	int		power;
	int		toi;
	int		verif;

	i = 0;
	toi = 0;
	verif = 1;
	if (str[i] == '-')
	{
		verif = -verif;
		i++;
	}
	power = max_power(str, base);
	while (str[i])
	{
		toi = toi + (hexa_to_int(str[i]) * power);
		power = power / base;
		i++;
	}
	return (verif * toi);
}
