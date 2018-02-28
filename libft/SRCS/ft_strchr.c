/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:29:10 by wfoulon           #+#    #+#             */
/*   Updated: 2017/11/08 12:51:46 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;
	size_t l;

	i = 0;
	l = ft_strlen(s) + 1;
	while (i < l)
	{
		if (*s == (unsigned char)c)
			return ((char*)s);
		i++;
		s++;
	}
	return (NULL);
}
