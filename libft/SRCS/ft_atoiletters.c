/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoiletters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:46:31 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:46:34 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoiletters(const char *str)
{
	int		i;
	long	result;
	int		neg;

	neg = 0;
	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' || (str[i] >= 'a'
		&& str[i] <= 'z'))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		result = result + (int)str[i] - '0';
		result = result * 10;
		i++;
	}
	return (neg == 1 ? -result / 10 : result / 10);
}
