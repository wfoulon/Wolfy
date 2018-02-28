/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:49:20 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/11 13:49:23 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		convert_hexa(char c)
{
	if (c > 47 && c < 58)
		return (c - 48);
	if (c > 64 && c < 71)
		return (c - 55);
	if (c > 96 && c < 103)
		return (c - 87);
	return (-1);
}

int		ft_hexa_to_int(char *str)
{
	int len;
	int pow;
	int res;

	res = 0;
	pow = 1;
	len = ft_strlen(str);
	while (len-- > 0)
	{
		if (convert_hexa(str[len] == -1))
			return (-1);
		res = res + pow * convert_hexa(str[len]);
		pow = pow * 16;
	}
	return (res);
}
