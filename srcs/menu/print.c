/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:27:00 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:27:02 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			print_settings(t_env *env, int x, int y)
{
	static int close = 0;

	env->menus->position.x = env->resolutionw / 2 - 150 + 20;
	env->menus->position.y = env->resolutionh / 2 - 300 + 350;
	if (x >= env->resolutionw / 2 - 150 + 20 && x <= env->resolutionw / 2 -
	150 + 280 && y >= env->resolutionh / 2 - 300 + 350 && y <=
	env->resolutionh / 2 - 300 + 420)
	{
		env->menus->image = SDL_LoadBMP(env->clic == 0 ?
		"./Images/set-menu-survol.bmp" : "./Images/set-menu-press.bmp");
		env->menus->menu = SDL_CreateTextureFromSurface(env->render,
			env->menus->image);
		SDL_FreeSurface(env->menus->image);
		close = (env->clic == 1 ? 1 : close);
 /*		if (close == 1 && env->clic == 0)
			ft_change_settings(env);*/
	}
	else
	{
		env->menus->image = SDL_LoadBMP("./Images/set-menu-vierge.bmp");
		env->menus->menu = SDL_CreateTextureFromSurface(env->render,
			env->menus->image);
		SDL_FreeSurface(env->menus->image);
		close = 0;
	}
	SDL_QueryTexture(env->menus->menu, NULL, NULL, &env->menus->position.w,
					 &env->menus->position.h);
	SDL_RenderCopy(env->render, env->menus->menu, NULL, &env->menus->position);
	SDL_DestroyTexture(env->menus->menu);
}
