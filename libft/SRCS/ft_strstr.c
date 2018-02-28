/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:32:11 by wfoulon           #+#    #+#             */
/*   Updated: 2017/11/09 16:55:17 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[j] != '\0')
	{
		i = 0;
		while (needle[i] == haystack[j + i])
		{
			i++;
			if (needle[i] == '\0')
				return ((char*)haystack + j);
		}
		j++;
	}
	return (NULL);
}
