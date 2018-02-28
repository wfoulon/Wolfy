/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:15:04 by wfoulon           #+#    #+#             */
/*   Updated: 2017/11/09 17:05:33 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_int_len(int n)
{
	int q;
	int i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		q = n % 10;
		q = n - q;
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		q;
	int		len;
	char	*toa;
	char	*tmp;

	if (n == -2147483648)
		return ("-2147483648");
	len = ft_int_len(n);
	toa = (char *)malloc(sizeof(char) * (len + 1));
	tmp = toa;
	if (n == 0 || !toa)
		return ("0");
	if (n < 0)
		toa[0] = '-';
	n = (n < 0 ? -n : n);
	toa[len] = '\0';
	while (n > 0)
	{
		toa[len-- - 1] = n % 10 + '0';
		q = n % 10;
		n = n - q;
		n = n / 10;
	}
	free(tmp);
	return (toa);
}
