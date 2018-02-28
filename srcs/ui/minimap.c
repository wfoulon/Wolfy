/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:37:37 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:37:39 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_minimap(t_env *env, int x, int y)
{
	SDL_Rect	position;

	x = -1;
	position.w = 600 / env->longmapx;
	position.h = 500 / env->longmapy;
    //printf("%d\n", position.w);
	//position.x = env->resolutionw * 0.43 - (env->posy * 20);
	//position.y = env->resolutionw * 0.35 - (env->posy * 20);
    position.y = (env->resolutionh - (position.h * env->longmapy) + position.h) * 0.5;
    while (++x < env->longmapx)
	{
		y = -1;
        position.x = (env->resolutionw - (position.w * env->longmapx) - position.w) * 0.5;
		while (++y < env->longmapy)
		{
			position.x += position.w - 1;
			if (env->worldmap[x][y] > 0)
				SDL_RenderCopy(env->render, env->twalltiles, NULL, &position);
			else
				SDL_RenderCopy(env->render, env->tfloortiles, NULL, &position);
			if (x == (int)env->posx && y == (int)env->posy)
				SDL_RenderCopy(env->render, env->tguy, NULL, &position);
		}
        position.y += position.h - 1;
        SDL_RenderDrawPoint(env->render, env->resolutionw * 0.5, env->resolutionh * 0.5);
    }
}
