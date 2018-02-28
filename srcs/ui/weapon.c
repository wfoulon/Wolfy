/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:37:46 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:37:47 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_weapon_shot(t_env *env, int *x, int *w)
{
	static double	i = 2.5;

	if (i == 2.5)
		mouseclk(env);
	*x = (i > 0 ? 307 : 0);
	*w = (i > 0 ? 70 : 64);
	if (i > 2)
	{
		*x = 150;
		*w = 85;
	}
	else if (i > 1)
	{
		*x = 377;
		*w = 93;
	}
	i = (i <= 0.0 ? 2.5 : i - 0.2);
	env->shot = (i == 2.5 ? 0 : 1);
}

void		ft_weapon(t_env *env)
{
	SDL_Rect			position;
	SDL_Rect			clip;
	static int			x = 0;
	static int			w = 64;

	if (env->shot == 1)
		ft_weapon_shot(env, &x, &w);
	position.x = env->resolutionw * 0.5 - 53;
	position.y = env->resolutionh - 212;
	position.w = 128;
	position.h = 212;
	clip.x = x;
	clip.y = 0;
	clip.w = w;
	clip.h = 106;
	SDL_RenderCopy(env->render, env->tpistol, &clip, &position);
}
