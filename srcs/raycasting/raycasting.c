/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:32:51 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:32:53 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_print_render(t_env *env)
{
	SDL_Rect position;
	static int i = 0;
	//void *pxl;

	position.x = 0;
	position.y = 0;
/* 	env->swall = SDL_CreateRGBSurfaceFrom(env->pixels, env->resolutionw,
		env->resolutionh, 32, env->resolutionw * sizeof(Uint32),
		env->format->Rmask, env->format->Gmask, env->format->Bmask,
		env->format->Amask); */
	if (++i == 1)
        env->twall = SDL_CreateTexture(env->render, SDL_PIXELFORMAT_ARGB8888,
            SDL_TEXTUREACCESS_STREAMING, env->resolutionw, env->resolutionh);
	//printf("%s\n", SDL_GetError());
	//SDL_LockTexture(env->twall, 0, (void **)&env->pixels, &env->twall->pitch);
	//pxl = env->twall->pixels;
	SDL_UpdateTexture(env->twall, NULL, env->pixels, env->resolutionw * sizeof(Uint32));
	//ft_memcpy(env->twall->pixels, env->pixels, sizeof(env->pixels));
	SDL_UnlockTexture(env->twall);
	//SDL_QueryTexture(env->twall, NULL, NULL, &position.w, &position.h);
	SDL_RenderCopy(env->render, env->twall, NULL, NULL);
	ft_weapon(env);
	ft_cursor(env);
	env->map == 1 ? ft_minimap(env, -1, -1) : 0;
	SDL_RenderPresent(env->render);
	SDL_RenderClear(env->render);
	//SDL_DestroyTexture(env->twall);
	//SDL_FreeSurface(env->swall);
}

void			ft_set_variable(t_env *env, int x)
{
//calcul position rayon et direction
	env->camerax = 2 * x / (double)env->resolutionw - 1;
	env->raydirx = env->dirx + env->camx * env->camerax;
	env->raydiry = env->diry + env->camy * env->camerax;
//dans quelle postion de map on est
	env->mapx = (int)env->posx;
	env->mapy = (int)env->posy;
//longueur du rayon de x ou yside jusquau prochain x ou prochain y side
	env->deltadistx = fabs(1 / env->raydirx);
	env->deltadisty = fabs(1 / env->raydiry);
	env->deltadistx = (env->deltadistx <= 0 ? 1 : env->deltadistx);
	env->deltadisty = (env->deltadisty <= 0 ? 1 : env->deltadisty);
	env->hit = 0; // si on touche un mur;
	env->stepx = (env->raydirx < 0 ? -1 : 1);
	env->sidedistx = (env->raydirx < 0 ? (env->posx - env->mapx) *
		env->deltadistx : (env->mapx + 1.0 - env->posx) * env->deltadistx);
//calcul du step  et de la distance de notre pos initiale a la prochaine pos
	env->stepy = (env->raydiry < 0 ? -1 : 1);
	env->sidedisty = (env->raydiry < 0 ? ((env->posy - env->mapy) *
		env->deltadisty) : ((env->mapy + 1.0 - env->posy) * env->deltadisty));
}

void			ft_check_value(t_env *env)
{
	env->lineheight = (int)(env->resolutionh / (env->perpwalldist));
	env->drawstart = (-env->lineheight * 0.5 + env->resolutionh * 0.5);
	env->drawstart = (env->drawstart < 0 ? 0 : env->drawstart);
	env->drawend = env->lineheight * 0.5 + env->resolutionh * 0.5;
	if (env->drawend >= env->resolutionh)
		env->drawend = env->resolutionh - 1;
//difference de luminosite entre les deux cotes
	/* if (env->side == 1)
		env->ombre = 128; */
//draw la ligne verticale
	env->wallx = (env->side == 0 ? env->posy + env->perpwalldist *
		env->raydiry : env->posx + env->perpwalldist * env->raydirx);
	env->wallx -= floor((env->wallx));
	env->texx = (int)(env->wallx * (double)(env->wall[env->textnum/* wallstex(env) */]->w));
	if (env->raydirx >= 0 && env->side == 0)
		env->textnum = 0;
	else if (env->raydiry >= 0 && env->side == 1)
		env->textnum = 1;
	else if (env->raydirx < 0 && env->side == 0)
		env->textnum = 2;
	else if (env->raydiry < 0 && env->side == 1)
		env->textnum = 3;
}

void			ft_calc_raycasting(t_env *env, int x)
{
	ft_set_variable(env, x);
	while (env->hit == 0)
	{
		if (env->sidedistx < env->sidedisty)
		{
			env->sidedistx += env->deltadistx;
			env->mapx += env->stepx;
			env->side = 0;
		}
		else
		{
			env->sidedisty += env->deltadisty;
			env->mapy += env->stepy;
			env->side = 1;
		}
		env->hit = (env->worldmap[env->mapx][env->mapy] > 0 ? 1 : 0);
	}
	env->perpwalldist = (env->side == 0 ? (env->mapx - env->posx +
		(1 - env->stepx) * 0.5) / env->raydirx : (env->mapy - env->posy +
			(1 - env->stepy) * 0.5) / env->raydiry);
	ft_check_value(env);
	//ft_begin_sky(env, env->floor, x);
	env->zbuffer[x] = env->perpwalldist;
 //   ft_printf("%d\n", env->perpwalldist);
	while (env->drawstart++ <= env->drawend)
		draw_texture(env, x);
	ft_begin_floor(env, env->floor, x);
}

void		raycasting(t_env *env, int x)
{
	(void)x;
	static Uint32 startclock = 0;
	static Uint32 deltaclock = 0;
	static Uint32 currentFPS = 0;

	deltaclock = SDL_GetTicks() - startclock;
	startclock = SDL_GetTicks();
	if (deltaclock != 0)
		currentFPS = 1000 / deltaclock;
	//ft_printf("%d\n", currentFPS);
	sdlthread(env);
	if (env->closeprog)
	{
		while (SDL_PollEvent(&env->events) > 0)
		{
			if (env->events.type == SDL_KEYDOWN)
				keypress(env);
			if (env->events.type == SDL_MOUSEBUTTONDOWN)
				env->shot = 1;
			if (env->events.type == SDL_KEYUP)
				keyrelease(env);
			if (env->events.type == SDL_MOUSEMOTION && env->menu == 0)
				mouse_rot(env);
		}
	}
}

