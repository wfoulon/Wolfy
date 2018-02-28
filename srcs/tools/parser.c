/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:36:25 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:36:27 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_strnblen(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (ft_isdigit(*str) == 1)
			i++;
		str++;
	}
	return (i);
}

int			*ft_getnb_from_str(char *str, int x)
{
	int		*tab;
	int		i;

	i = 0;
	tab = (int *)malloc(sizeof(int) * x);
	while (*str)
	{
		if (ft_isdigit(*str) == 1)
			tab[i++] = (int)(*str) - 48;
		str++;
	}
	return (tab);
}

void		ft_check_firstandlast(int *tab, t_env *env)
{
	int i;

	i = 0;
	while (i < env->longmapx)
	{
		if (tab[i++] == 0)
			ft_exit(env);
	}
}

void		ft_check_map(t_env *env, int *tab)
{
	if (tab[0] == 0 || tab[env->longmapx - 1] == 0)
		ft_exit(env);
}

void		parse_map(t_env *env, int ymap)
{
	int		fd;
	char	*line;
	
	if ((fd = open(env->mapaddr, O_RDONLY)) < 0)
		ft_exit(env);
	while (get_next_line(fd, &line) > 0)
	{
		env->longmapx = (env->longmapx == 0 ? ft_strnblen(line) : env->longmapx);
		env->longmapx != ft_strnblen(line) ? ft_exit(env) : 0;
		ymap++;
		free(line);
	}
	env->longmapx == 0 || ymap == 0 ? ft_exit(env) : 0;
	env->longmapx = env->longmapx;
	env->longmapy = ymap;
	free(line);
	close(fd);
	fd = open(env->mapaddr, O_RDONLY);
	env->worldmap = (int **)malloc(sizeof(int *) * ymap);
	ymap = 0;
	while (get_next_line(fd, &line) > 0)
	{
		env->worldmap[ymap++] = ft_getnb_from_str(line, ft_strnblen(line));
		if ((ymap - 1) == 0 || (ymap - 1) == env->longmapy)
			ft_check_firstandlast(env->worldmap[ymap - 1], env);
		ft_check_map(env, env->worldmap[ymap - 1]);
		free(line);
	}
	//ft_check_map(env->worldmap);
	free(line);
}
