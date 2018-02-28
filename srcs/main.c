/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:25:38 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:25:53 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			main(int ac, char **av)
{
	t_env	*env;

	if (ac < 2)
	{
		ft_putstr("pas de fichier\nusage:\n./wold3d /maps/map**");
		exit(1);
	}
	srand(time(NULL));
	env = (t_env *)malloc(sizeof(t_env));
	get_resolution(env);
	env->mapaddr = av[1];
	if (sdl_initenv(env) == 1)
		ft_exit(env);
	ft_init_menu(env);
	SDL_WarpMouseGlobal(1280, 1400);
	ft_init_menu(env);
/*	if (wolf_audio(&env->audio))
		ft_putstr("Audio error");
	env->audio.audiolen = 5000;
	env->audio.play = 0;*/
	sdl_loop(env);
	return (0);
}
