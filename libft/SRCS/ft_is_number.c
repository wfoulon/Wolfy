/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:35:21 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/11 14:35:31 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Renvoie 1 si le char * est juge egal a un nombre negatif ou positif.
**Un nombre d'espaces consecutifs au debut est accepte, puis un - ou un +
**et ensuite les nombres successifs
*/

int		ft_is_number(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
