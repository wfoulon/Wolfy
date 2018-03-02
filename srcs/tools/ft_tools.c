/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:36:19 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:36:20 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_menu(t_env *env)
{
	env->menu = (env->menu == 1 ? 0 : 1);
	SDL_ClearQueuedAudio(env->effects->device);
	SDL_QueueAudio(env->effects->device, env->effects->wavbuffer,
	env->effects->wavlength);
	SDL_SetRelativeMouseMode(env->menu == 0 ? 1 : 0);
	SDL_WarpMouseInWindow(env->screen, env->resolutionw / 2,
	env->resolutionh / 2);
	SDL_SetRelativeMouseMode(env->menu == 0 ? 1 : 0);
	SDL_ShowCursor(env->menu == 1 ? 1 : 0);
	env->menuset = 0;
}

int		ft_checkmap(t_env *env, int key)
{
	if (key == 1)
		return (env->worldmap[(int)(env->posx + (env->dirx * MOVESPEED *
			env->shift) * 0.30)][(int)(env->posy + (env->diry * MOVESPEED *
			env->shift) * 0.30)]);
	else if (key == 2)
		return (env->worldmap[(int)(env->posx - (env->dirx * MOVESPEED *
			env->shift) * 0.30)][(int)(env->posy - (env->diry * MOVESPEED *
			env->shift) * 0.30)]);
	else if (key == 3)
		return (env->worldmap[(int)(env->posx + (env->diry * MOVESPEED *
			env->shift) * 0.30)][(int)(env->posy - (env->dirx * MOVESPEED *
			env->shift) * 0.30)]);
	else if (key == 4)
		return (env->worldmap[(int)(env->posx - (env->diry * MOVESPEED *
			env->shift) * 0.30)][(int)(env->posy + (env->dirx * MOVESPEED *
			env->shift) * 0.30)]);
	else
		return (0);
}

void	exitaudio(t_env *env)
{
	/* SDL_FreeWAV(env->audio.audiobuffer); */
	SDL_FreeWAV(env->shots->wavbuffer);
	SDL_FreeWAV(env->steps->wavbuffer);
	SDL_FreeWAV(env->steps->wavbuffer2);
	SDL_FreeWAV(env->effects->wavbuffer);
	SDL_FreeWAV(env->effects->wavbuffer2);
	SDL_FreeWAV(env->effects->wavbuffer3);
	SDL_CloseAudioDevice(env->effects->device);
	SDL_CloseAudioDevice(env->effects->device2);
	SDL_CloseAudioDevice(env->effects->device3);
	SDL_CloseAudioDevice(env->steps->device);
	SDL_CloseAudioDevice(env->steps->device2);
	SDL_CloseAudioDevice(env->shots->device);
	SDL_CloseAudio();
}

void	ft_exit(t_env *env)
{
/*	SDL_FreeSurface(env->wall);*/
	SDL_DestroyRenderer(env->render);
	SDL_DestroyWindow(env->screen);
	exitaudio(env);
	SDL_Quit();
	env = NULL;
	free(env);
	exit(1);
}

void ft_str_error(t_env *e, char *str)
{
	ft_putendl("Error :");
	ft_putendl(str);
	e = NULL;
	exit(EXIT_FAILURE);
}
