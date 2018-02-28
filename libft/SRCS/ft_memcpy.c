/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:40:47 by wfoulon           #+#    #+#             */
/*   Updated: 2017/11/07 17:49:34 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)dst;
	while (i < n)
	{
		*s = *(char *)src;
		s++;
		src++;
		i++;
	}
	return (dst);
}
