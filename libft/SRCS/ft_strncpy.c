/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:08:20 by wfoulon           #+#    #+#             */
/*   Updated: 2017/11/07 16:19:02 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t a;

	a = 0;
	if (!dst && !src)
		return (NULL);
	ft_bzero(dst, len);
	while (src[a] && a < len)
	{
		dst[a] = src[a];
		a++;
	}
	return (dst);
}
