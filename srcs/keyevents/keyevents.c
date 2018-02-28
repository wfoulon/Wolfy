/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevents.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:31:18 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:31:20 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	changecolor(t_env *env)
{
	env->r = rand() % 256;
	env->g = rand() % 256;
	env->b = rand() % 256;
}

void	ft_keyevent(t_env *env)
{
	if (env->up || env->down || env->right || env->left)
	{
		if (env->up == 1 && ft_checkmap(env, 1) == 0)
		{
			env->posx += (env->dirx * MOVESPEED * env->shift) * 0.25;
			env->posy += (env->diry * MOVESPEED * env->shift) * 0.25;
		}
		if (env->down == 1 && ft_checkmap(env, 2) == 0)
		{
			env->posx -= (env->dirx * MOVESPEED * env->shift) * 0.25;
			env->posy -= (env->diry * MOVESPEED * env->shift) * 0.25;
		}
		if (env->right == 1 && ft_checkmap(env, 3) == 0)
		{
			env->posy -= (env->dirx * MOVESPEED * env->shift) * 0.25;
			env->posx += (env->diry * MOVESPEED * env->shift) * 0.25;
		}
		if (env->left == 1 && ft_checkmap(env, 4) == 0)
		{
			env->posy += (env->dirx * MOVESPEED * env->shift) * 0.25;
			env->posx -= (env->diry * MOVESPEED * env->shift) * 0.25;
		}
		stepscalcs(env);
	}
}

int		keyrelease(t_env *env)
{
	if (env->events.key.keysym.sym == SDLK_w)
		env->up = 0;
	if (env->events.key.keysym.sym == SDLK_s)
		env->down = 0;
	if (env->events.key.keysym.sym == SDLK_d)
		env->right = 0;
	if (env->events.key.keysym.sym == SDLK_a)
		env->left = 0;
	if (env->events.key.keysym.sym == SDLK_TAB)
		env->map = 0;
	if (env->events.key.keysym.sym == SDLK_LSHIFT)
		env->shift = 1;
	return (1);
}

void	keypress2(t_env *env)
{
	if (env->events.key.keysym.sym == SDLK_SPACE)
		changecolor(env);
	if (env->events.key.keysym.sym == SDLK_w)
		env->up = 1;
	if (env->events.key.keysym.sym == SDLK_s)
		env->down = 1;
	if (env->events.key.keysym.sym == SDLK_d)
		env->right = 1;
	if (env->events.key.keysym.sym == SDLK_a)
		env->left = 1;
	if (env->events.key.keysym.sym == SDLK_m)
		manage_key(env);
	if (env->events.key.keysym.sym == SDLK_TAB)
		env->map = 1;
	if (env->events.key.keysym.sym == SDLK_LSHIFT)
		env->shift = 2;
}

int		keypress(t_env *env)
{
	if (env->events.key.keysym.sym == SDLK_ESCAPE)
		ft_init_menu(env);
	manage_volume(env);
	keypress2(env);
	env->events.motion.x = env->mousex;
	return (1);
}

