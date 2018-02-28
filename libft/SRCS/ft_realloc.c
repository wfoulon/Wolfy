/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:18:34 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/11 15:18:36 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_realloc(void *ptr, size_t new, size_t old)
{
	void	*p;

	if (!ptr)
		return (ft_memalloc(new));
	if (new == 0)
	{
		free(ptr);
		ptr = NULL;
		return (NULL);
	}
	if (!(p = ft_memalloc(new)))
		return (NULL);
	ft_memcpy(p, ptr, old);
	free(ptr);
	ptr = NULL;
	return (p);
}
