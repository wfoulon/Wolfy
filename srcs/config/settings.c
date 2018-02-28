/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:29:48 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:29:49 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "wolf3d.h"

void	get_resolution(t_env *env)
{
	char	*line;
	int		fd;

	fd = open("./srcs/config/settings", O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strnequ("resolutionw", line, 11) == 1)
			env->resolutionw = ft_atoiletters(line);
		if (ft_strnequ("resolutionh", line, 11) == 1)
			env->resolutionh = ft_atoiletters(line);
		if (ft_strnequ("fullscreen", line, 10) == 1)
			env->fullscreen = ft_atoiletters(line);
		free(line);
	}
	free(line);
}