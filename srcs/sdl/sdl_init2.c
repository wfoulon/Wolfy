/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:26:17 by wfoulon           #+#    #+#             */
/*   Updated: 2018/03/02 12:26:28 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	sdl_loop(t_env *env)
{
	env->closeprog = 1;
	while (1)
		raycasting(env, 0);
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
