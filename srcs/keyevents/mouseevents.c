/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouseevents.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:31:34 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:31:36 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	mouseclk(t_env *env)
{
	if (env->events.button.button == SDL_BUTTON_LEFT && env->menu == 0 &&
	env->shift != 2)
	{
		SDL_ClearQueuedAudio(env->shots->device);
		SDL_QueueAudio(env->shots->device, env->shots->wavbuffer,
		env->shots->wavlength);
	}
}
