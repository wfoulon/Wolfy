/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdlthread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:33:00 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:33:01 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				raycalc(void *tab)
{
	t_env		*env;
	int			i;

	i = 0;
	env = (t_env *)tab;
	while (I < 1024)
		ft_calc_raycasting(env, i++);
	return (i);
}

void			sdlgamethread(t_env *e, int i)
{
	int			tmp;
	SDL_Thread	**t;

	tmp = 0;
	t = (SDL_Thread **)malloc(sizeof(SDL_Thread *) * i);
	while (tmp < i)
	{
		if ((!(t[tmp] = SDL_CreateThread(raycalc, NULL,
		&e[tmp]))))
	    	ft_putstr(SDL_GetError());
		else
			SDL_WaitThread(t[tmp], NULL);
		tmp++;
	}
	free(t);
}

void			sdlthread(t_env *env)
{
	int			tmp;
	int			i;
	t_env		*e;

	tmp = 0;
	i = env->resolutionw / 160;
	if (!(e = (t_env *)malloc(sizeof(t_env) * i)))
		ft_str_error(env, "MALLOC FAILURE");
	while (tmp < i)
	{
		ft_memcpy((void *)&e[tmp], (void *)env, sizeof(t_env));
		e[tmp].x = env->resolutionw / i * tmp;
		e[tmp].x_max = (env->resolutionw * (tmp + 1)) / i;
		tmp++;
	}
	ft_createpxl(env);
	/* sdlgamethread(e, i);
	if (env->menu == 0)
	{
		ft_sprites(env);
		ft_print_render(env);
		ft_keyevent(env);
	}
	else
		ft_menu(env); */
	free(e);
}
