/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:37:30 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:37:31 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_cursor(t_env *env)
{
	int		x;
	int		y;

	x = env->resolutionw / 2 - 10;
	y = env->resolutionh / 2 - 10;
	SDL_SetRenderDrawColor(env->render, 255, 255, 255, 0);
	while (x != env->resolutionw * 0.5 + 10 && y != env->resolutionh * 0.5 + 10)
	{
		if (!(x > env->resolutionw * 0.5 - 3 && x < env->resolutionw * 0.5 + 3))
			SDL_RenderDrawPoint(env->render, x, env->resolutionh * 0.5);
		if (!(y > env->resolutionh * 0.5 - 3 && y < env->resolutionh * 0.5 + 3))
			SDL_RenderDrawPoint(env->render, env->resolutionw * 0.5, y);
		y++;
		x++;
	}
	SDL_RenderDrawPoint(env->render, env->resolutionw * 0.5,
env->resolutionh * 0.5);
}

double		get_sens(t_env *env)
{
	int		i;

	i = 1;
	if (env->shift == 2)
		return (ROTSPEED * 1.8);
	while (i < 5)
	{
	if (ft_checkmap(env, i) > 0)
		return (ROTSPEED * 2);
		i++;
	}
	return (ROTSPEED * 1.2);
}

void		mouse_rot(t_env *env)
{
	int		x;
	double	mr;

	mr = get_sens(env);
	x = env->events.motion.x;
	x = (x > env->resolutionw ? env->resolutionw - 1 : x);
	env->olddirx = env->dirx;
	if (x < env->mousex || x == 0)
	{
		env->dirx = env->dirx * cos(mr) - env->diry * sin(mr);
		env->diry = env->olddirx * sin(mr) + env->diry * cos(mr);
		env->oldcamerax = env->camx;
		env->camx = env->camx * cos(mr) - env->camy * sin(mr);
		env->camy = env->oldcamerax * sin(mr) + env->camy * cos(mr);
		env->mousex = env->events.motion.x;
	}
	else if (x > env->mousex || x == env->resolutionw - 1)
	{
		env->dirx = env->dirx * cos(-mr) - env->diry * sin(-mr);
		env->diry = env->olddirx * sin(-mr) + env->diry * cos(-mr);
		env->oldcamerax = env->camx;
		env->camx = env->camx * cos(-mr) - env->camy * sin(-mr);
		env->camy = env->oldcamerax * sin(-mr) + env->camy * cos(-mr);
		env->mousex = env->events.motion.x;
	}
}
