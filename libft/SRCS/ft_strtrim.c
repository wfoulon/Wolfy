/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:58:02 by wfoulon           #+#    #+#             */
/*   Updated: 2017/11/08 18:12:33 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int i;
	int len;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_isspace(s[i]) == 1)
	{
		i++;
		if (s[i] == '\0')
			return (ft_strdup(""));
	}
	len = ft_strlen(s);
	if (s[len] == '\0')
		len--;
	while (ft_isspace(s[len]) == 1)
		len--;
	return (ft_strsub(s, i, len - i + 1));
}
