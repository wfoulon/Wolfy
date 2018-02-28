/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:15:00 by wfoulon           #+#    #+#             */
/*   Updated: 2017/11/10 12:48:30 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char const *str, int i, char c)
{
	int		count;

	count = i;
	while (str[count] != c && str[count])
		count++;
	return (count - i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	if (s == NULL || !(tab = (char**)malloc(sizeof(char*) * ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] && s[i] != c)
		{
			k = 0;
			tab[j] = ft_memalloc(ft_count(s, i, c) + 1);
			while (s[i] != c && s[i])
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
