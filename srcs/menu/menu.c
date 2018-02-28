/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:26:50 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:26:55 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_menu_audio(t_env *env, int x, int y)
{
	if ((x >= env->resolutionw / 2 - 150 + 20 && x <= env->resolutionw / 2 - 150
	+ 280 && y >= env->resolutionh / 2 - 300 + 480 && y <= env->resolutionh / 2
	- 300 + 550) || (x >= env->resolutionw / 2 - 150 + 20 && x <=
	env->resolutionw / 2 - 150 + 280 && y >= env->resolutionh / 2 - 300 +
	350 && y <= env->resolutionh / 2 - 300 + 420))
	{
		env->soundclic == 0 ? SDL_QueueAudio(env->effects->device2,
		env->effects->wavbuffer2, env->effects->wavlength2) : 0;
		env->soundclic = 1;
		if (env->clic == 1 && env->soundbutton == 0)
		{
			SDL_QueueAudio(env->effects->device3,
			env->effects->wavbuffer3, env->effects->wavlength3);
			env->soundbutton = 1;
		}
	}
	else
	{
		SDL_ClearQueuedAudio(env->effects->device3);
		SDL_ClearQueuedAudio(env->effects->device2);
		env->soundbutton = 0;
		env->soundclic = 0;
	}
}

void			print_exit(t_env *env, int x, int y)
{
	static int close = 0;

	env->menus->position.x = env->resolutionw / 2 - 150 + 20;
	env->menus->position.y = env->resolutionh / 2 - 300 + 485;
	if (x >= env->resolutionw / 2 - 150 + 20 && x <= env->resolutionw / 2 -
	150 + 280 && y >= env->resolutionh / 2 - 300 + 485 && y <=
	env->resolutionh / 2 - 300 + 550)
	{
		env->menus->image = SDL_LoadBMP(env->clic == 0 ?
		"./Images/Exit-menu-survol.bmp" : "./Images/Exit-menu-press.bmp");
		env->menus->menu = SDL_CreateTextureFromSurface(env->render,
			env->menus->image);
		SDL_FreeSurface(env->menus->image);
		close = (env->clic == 1 ? 1 : close);
		if (close == 1 && env->clic == 0)
			ft_exit(env);
	}
	else
	{
		env->menus->image = SDL_LoadBMP("./Images/Exit-menu-vierge.bmp");
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

void			ft_check_menu(t_env *env, int x, int y)
{
	print_exit(env, x, y);
/* 	print_settings(env, x, y); */
/* 	print_continue(env, x, y);
	print_save(env, x, y); */
	ft_menu_audio(env, x, y);
	SDL_RenderPresent(env->render);
	SDL_RenderClear(env->render);
}

void			print_background(t_env *env)
{
	env->menus->image = SDL_LoadBMP("./Images/behindmenu.bmp");
	env->menus->menu = SDL_CreateTextureFromSurface(env->render,
		env->menus->image);
	SDL_FreeSurface(env->menus->image);
	env->menus->position.x = 0;
	env->menus->position.y = 0;
	SDL_QueryTexture(env->menus->menu, NULL, NULL, &env->menus->position.w,
		&env->menus->position.h);
	SDL_RenderCopy(env->render, env->menus->menu, NULL, &env->menus->position);
	SDL_DestroyTexture(env->menus->menu);
}

void			ft_menu(t_env *env)
{
	static int		x;
	static int		y;


	SDL_SetRenderDrawColor(env->render, 0, 0, 0, 0);
	if (env->menuset >= 0)
	{
		print_background(env);
		env->menus->image = SDL_LoadBMP("./Images/menu.bmp");
		env->menus->menu = SDL_CreateTextureFromSurface(env->render,
			env->menus->image);
		SDL_FreeSurface(env->menus->image);
		env->menus->position.x = env->resolutionw / 2 - 150;
		env->menus->position.y = env->resolutionh / 2 - 300;
		SDL_QueryTexture(env->menus->menu, NULL, NULL, &env->menus->position.w,
			&env->menus->position.h);
		SDL_RenderCopy(env->render, env->menus->menu, NULL,
			&env->menus->position);
		SDL_DestroyTexture(env->menus->menu);
		env->menuset = 1;
	}  
	env->clic = SDL_GetMouseState(&x, &y);
	ft_check_menu(env, x, y);
	SDL_RenderClear(env->render);
}
