/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:13:39 by wfoulon           #+#    #+#             */
/*   Updated: 2017/11/08 14:26:15 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *esp;

	if (size == 0 || !size)
		return (NULL);
	size += 1;
	if (!(esp = (void *)malloc(sizeof(void*) * size)))
		return (NULL);
	ft_bzero(esp, size);
	return (esp);
}
