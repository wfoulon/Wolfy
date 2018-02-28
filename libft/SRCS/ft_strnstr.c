/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:40:39 by wfoulon           #+#    #+#             */
/*   Updated: 2017/11/10 11:47:12 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*tmp;
	char	*mem;
	size_t	size;

	mem = (char *)(s1 + len);
	size = ft_strlen(s2);
	tmp = (char *)s1;
	if (!size)
		return ((char *)s1);
	while ((tmp = ft_strchr(tmp, *s2)) && tmp <= mem)
	{
		if ((tmp + size <= mem) && !ft_strncmp(tmp, s2, size))
			return (tmp);
		tmp++;
	}
	return (NULL);
}
