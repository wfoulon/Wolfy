/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:35:12 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:35:13 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_env3(t_env *env)
{
	env->stepscalc = 1;
	env->oldtime = 0;
	env->up = 0;
	env->down = 0;
	env->left = 0;
	env->right = 0;
	env->hit = 0;
	env->camx = 0;
	env->camy = 0.66;
	env->menu = 0;
	env->menuset = 0;
	env->clic = 0;
	env->shift = 1;
	env->longmapx = 0;
	env->longmapy = 0;
	env->zbuffer = (double *)malloc(sizeof(double) * env->resolutionw);
	/* env->spriteorder = (int *)malloc(sizeof(int) * NUMSPRITES);
	env->spritedistance = (double *)malloc(sizeof(double) * NUMSPRITES); */
	env->floor = (t_floor *)malloc(sizeof(t_floor));
}

void	init_env2(t_env *env)
{
	init_env3(env);
	env->guy = SDL_LoadBMP("Images/guy.bmp");
	env->tguy = SDL_CreateTextureFromSurface(env->render, env->guy);
	env->walltiles = SDL_LoadBMP("Images/walltiles.bmp");
	env->twalltiles = SDL_CreateTextureFromSurface(env->render, env->walltiles);
	env->floortiles = SDL_LoadBMP("Images/floortiles.bmp");
	env->tfloortiles = SDL_CreateTextureFromSurface(env->render, env->floortiles);
	env->pistol = SDL_LoadBMP("Images/Pistol3.bmp");
	env->tpistol = SDL_CreateTextureFromSurface(env->render, env->pistol);
	env->menus = (t_menu *)malloc(sizeof(t_menu));
	parse_map(env, 0);
	env->pixels = (Uint32 *)malloc(sizeof(Uint32) * env->resolutionw *
	env->resolutionh);
	env->format = SDL_AllocFormat(SDL_PIXELFORMAT_ARGB8888);
	env->wall = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 4);
	env->wall[0] = SDL_LoadBMP("Images/floor3.bmp");
	env->wall[1] = SDL_LoadBMP("Images/test3.bmp");
	env->wall[2] = SDL_LoadBMP("Images/floor1.bmp");
	env->wall[3] = SDL_LoadBMP("Images/test.bmp");
	env->sfloor = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 2);
	env->sfloor[0] = SDL_LoadBMP("./Images/floor9.bmp");
	env->sfloor[1] = SDL_LoadBMP("./Images/solgrass.bmp");
	env->ssky = SDL_LoadBMP("./Images/floor5.bmp");
	/* env->spritesur = SDL_LoadBMP("./Images/barrel.bmp"); */
	ft_putstr(SDL_GetError());
	env->keystate = SDL_GetKeyboardState(NULL);
	SDL_WarpMouseInWindow(env->screen, env->resolutionw *
	0.5, env->resolutionh * 0.5);
	SDL_SetRelativeMouseMode(1);
}

void	init_env(t_env *env)
{
	env->r = 120;
	env->g = 0;
	env->b = 10;
	env->posx = 12;
	env->posy = 5;
	env->dirx = -1;
	env->diry = 0;
	env->camx = 0;
	env->mousex = env->resolutionw * 0.5;
	env->test = 0;
	env->camy = 0.66;
	env->time = 0;
	env->soundclic = 0;
	env->soundbutton = 0;
	env->shot = 0;
	stepsound(env);
	ft_menuopen(env);
	soundshot(env);
	init_env2(env);
}

void	sdl_errors(t_env *env)
{
	if (env->screen != NULL)
		SDL_DestroyWindow(env->screen);
	if (env->render != NULL)
		SDL_DestroyRenderer(env->render);
	ft_putstr(SDL_GetError());
	env = NULL;
	free(env);
	SDL_Quit();
	exit(1);
}

int		sdl_initenv(t_env *env)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
		return (1);
	if ((env->screen = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, env->resolutionw, env->resolutionh,
		(env->fullscreen == 1 ? SDL_WINDOW_FULLSCREEN :
		SDL_WINDOW_SHOWN)/*  | SDL_WINDOW_OPENGL */)) == NULL)
		sdl_errors(env);
	if ((env->render = SDL_CreateRenderer(env->screen, -1,
		SDL_RENDERER_ACCELERATED)) == NULL)
		sdl_errors(env);
	init_env(env);
	return (0);
}

void	sdl_loop(t_env *env)
{
	env->closeprog = 1;
	while (1)
		raycasting(env, 0);
}
