/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:28:27 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:28:30 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "wolf3d.h"

void			audiocallback(void *udata, Uint8 *stream, int len)
{
	t_audio		*audio;

	audio = (t_audio *)udata;
	if (audio->audiolen == 0)
		return ;
	ft_memset(stream, 0, len);
	if (audio->audiopos < audio->audiolen)
	{
		if (audio->audiopos + len > audio->audiolen)
			len = audio->audiolen - audio->audiopos;
		SDL_MixAudio(stream, audio->audiobuffer + audio->audiopos, \
			len, audio->volume);
		audio->audiopos += len;
	}
	audio->audiolen -= len;
}

int				init_audio(t_audio *audio)
{
	audio->audiospec.freq = 44180;
	audio->audiospec.format = AUDIO_S16;
	audio->audiospec.channels = 2;
	audio->audiospec.samples = 1024;
	audio->audiospec.callback = audiocallback;
	audio->volume = 64;
	audio->audiospec.userdata = audio;
	if (SDL_OpenAudio(&audio->audiospec, NULL) < 0)
	{
		ft_putstr("Erreur à l'ouverture du fichier.\n");
		return (-1);
	}
	return (0);
}

int				wolf_audio(t_audio *audio)
{
	if (init_audio(audio))
		return (1);
	if (!(SDL_LoadWAV(SOUND_1, &audio->audiospec, \
		&audio->audiobuffer, &audio->audiobufferlen)))
	{
		ft_putstr("Erreur lors du chargement du ficher WAV.\n");
		return (1);
	}
	return (0);
}

void			manage_key(t_env *env)
{
	if (env->audio.play == 0)
	{
		SDL_PauseAudio(0);
		env->audio.play = 1;
	}
	else if (env->audio.play == 1)
	{
		env->audio.play = 0;
		SDL_PauseAudio(1);
	}
}

void			manage_volume(t_env *env)
{
	if (env->events.key.keysym.sym == SDLK_KP_MINUS)
		env->audio.volume--;
	if (env->events.key.keysym.sym == SDLK_KP_PLUS)
		env->audio.volume++;
}
 */
