/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:20:10 by wfoulon           #+#    #+#             */
/*   Updated: 2017/11/08 16:45:20 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	p = ft_strnew(len);
	if (p == NULL || s == NULL || start > ft_strlen(s)
			|| start + len > ft_strlen(s))
		return (NULL);
	while (i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	return (p);
}
