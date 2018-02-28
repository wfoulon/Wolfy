/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soundeffects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:28:37 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:28:39 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		stepscalcshift(t_env *env)
{
	if (env->stepscalc % 16 == 0)
	{
		SDL_ClearQueuedAudio(env->steps->device);
		SDL_QueueAudio(env->steps->device, env->steps->wavbuffer,
		env->steps->wavlength);
	}
	else if (env->stepscalc % 8 == 0)
	{
		SDL_ClearQueuedAudio(env->steps->device2);
		SDL_QueueAudio(env->steps->device2, env->steps->wavbuffer2,
		env->steps->wavlength2);
	}
}

void		stepscalcs(t_env *env)
{
	if (env->shift != 2)
	{
		if (env->stepscalc % 26 == 0)
		{
			SDL_ClearQueuedAudio(env->steps->device);
			SDL_QueueAudio(env->steps->device, env->steps->wavbuffer,
			env->steps->wavlength);
		}
		else if (env->stepscalc % 13 == 0)
		{
			SDL_ClearQueuedAudio(env->steps->device2);
			SDL_QueueAudio(env->steps->device2, env->steps->wavbuffer2,
			env->steps->wavlength2);
		}
	}
	else
		stepscalcshift(env);
	env->stepscalc++;
	if (env->stepscalc == 2147483646)
		env->stepscalc = 0;
}

void		soundshot(t_env *env)
{
	env->shots = (t_shots*)malloc(sizeof(t_shots));
	SDL_LoadWAV(SOUND_SHOT, &env->shots->wavspec, &env->shots->wavbuffer,
	&env->shots->wavlength);
	env->shots->device = SDL_OpenAudioDevice(NULL, 0, &env->shots->wavspec,
	NULL, 0);
	SDL_PauseAudioDevice(env->shots->device, 0);
}

void		ft_menuopen(t_env *env)
{
	env->effects = (t_effects*)malloc(sizeof(t_effects));
	SDL_LoadWAV(SOUND_MENU, &env->effects->wavspec, &env->effects->wavbuffer,
	&env->effects->wavlength);
	env->effects->device = SDL_OpenAudioDevice(NULL, 0, &env->effects->wavspec,
	NULL, 0);
	SDL_PauseAudioDevice(env->effects->device, 0);
	SDL_LoadWAV(SOUND_MENU2, &env->effects->wavspec2, &env->effects->wavbuffer2,
	&env->effects->wavlength2);
	env->effects->device2 = SDL_OpenAudioDevice(NULL, 0,
	&env->effects->wavspec2, NULL, 0);
	SDL_PauseAudioDevice(env->effects->device2, 0);
	SDL_LoadWAV(SOUND_MENU3, &env->effects->wavspec3, &env->effects->wavbuffer3,
	&env->effects->wavlength3);
	env->effects->device3 = SDL_OpenAudioDevice(NULL, 0,
	&env->effects->wavspec3, NULL, 0);
	SDL_PauseAudioDevice(env->effects->device3, 0);
}

void		stepsound(t_env *env)
{
	env->steps = (t_steps*)malloc(sizeof(t_steps));
	SDL_LoadWAV(SOUND_STEP, &env->steps->wavspec, &env->steps->wavbuffer,
	&env->steps->wavlength);
	env->steps->device = SDL_OpenAudioDevice(NULL, 0, &env->steps->wavspec,
	NULL, 0);
	SDL_PauseAudioDevice(env->steps->device, 0);
	SDL_LoadWAV(SOUND_STEP2, &env->steps->wavspec2, &env->steps->wavbuffer2,
	&env->steps->wavlength2);
	env->steps->device2 = SDL_OpenAudioDevice(NULL, 0, &env->steps->wavspec2,
	NULL, 0);
	SDL_PauseAudioDevice(env->steps->device2, 0);
}
