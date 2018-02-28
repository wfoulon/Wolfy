/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:33:20 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:33:22 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/* void        ft_swapdouble(double *a, double *b)
{
	double     tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void        ft_swap(int *a, int *b)
{
	int     tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


void        sortsprites(t_env *env, int amount)
{
	int     gap;
	int     swap;
	int     i;
	int     j;

	i = -1;
	gap = amount;
	swap = 0;
	while (gap > 1 || swap != 0)
	{
	   // printf("hello\n");
		gap = (gap * 10) / 13;
		if (gap == 9 || gap == 10)
			gap = 11;
		if (gap < 1)
			gap = 1;
		swap = 0;
		i = -1;
		while (++i < amount - gap)
		{
			j = i + gap;
			if (env->spritedistance[i] < env->spritedistance[j])
				{
					ft_swapdouble(&env->spritedistance[i], &env->spritedistance[j]);
					ft_swap(&env->spriteorder[i], &env->spriteorder[j]);
					swap = 1;
				}
		}
	}
}


void        ft_sprites(t_env *env)
{
	int     i;
	int     y;
	t_sprite    sprite[NUMSPRITES] =
	{
		{ 14.5, 14.5, 1},
		{ 12.5, 12.5, 1},
	};

	i = -1;
	while (++i < NUMSPRITES)
	{
		env->spriteorder[i] = i;
		env->spritedistance[i] = ((env->posx - sprite[i].x) *
(env->posx - sprite[i].x) + (env->posy - sprite[i].y) *
(env->posy - sprite[i].y));
	}
	sortsprites(env, NUMSPRITES);
	i = -1;
	while (++i < NUMSPRITES)
	{
		env->spritex = sprite[env->spriteorder[i]].x - env->posx;
		env->spritey = sprite[env->spriteorder[i]].y - env->posy;
		
		env->invdet = 1.0 / (env->camx * env->diry - env->dirx * env->camy);
		env->transformx = env->invdet * (env->diry * env->spritex - env->dirx * env->spritey);
		env->transformy = env->invdet * (-env->camy * env->spritex + env->camx * env->spritey);
		env->spritescreenx = (int)((env->resolutionw / 2) * (1 + env->transformx / env->transformy));
		env->spriteheight = abs((int)(env->resolutionh / env->transformy));
		env->drawstarty = -env->spriteheight / 2 + env->resolutionh / 2;
		if (env->drawstarty < 0)
			env->drawstarty = 0;
		env->drawendy = env->spriteheight / 2 + env->resolutionh / 2;
		if (env->drawendy >= env->resolutionh)
			env->drawendy = env->resolutionh - 1;
		env->spritewidth = abs((int)(env->resolutionh / env->transformy));
		env->drawstartx = -env->spritewidth / 2 + env->spritescreenx;
		if (env->drawstartx < 0)
			env->drawstartx = 0;
		env->drawendx = env->spritewidth / 2 + env->spritescreenx;
		if (env->drawendx >= env->resolutionw)
			env->drawendx = env->resolutionw - 1;

		env->stripe = env->drawstartx - 1;
		while (++env->stripe < env->drawendx)
		{
			env->spritetex = (int)((env->stripe - (-env->spritewidth / 2 + env->spritescreenx)) * SWIDTH / env->spritewidth);
			if (env->transformy > 0 && env->stripe > 0 && env->stripe < env->resolutionw && env->transformy < env->zbuffer[env->stripe])
			{
				y = env->drawstarty;
				while (y < env->drawendy)
				{
					//ft_printf("%ld : %ld\n", env->drawstarty, env->drawendy);
					env->d = (y) * 256 - env->resolutionh * 128 + env->spriteheight * 128;
					env->spritetexy = ((env->d * SHEIGHT) /  env->spriteheight) / 256;
					getrgb2(get_pixel(env->spritesur, env->spritetex, env->spritetexy), env, SPRITE);
					env->spritecolor =  RGB(env->pxlsprite[0], env->pxlsprite[1], env->pxlsprite[2]);
					if ((env->spritecolor & 0x00FFFFFF) != 0)
						env->pixels[y * env->resolutionw + env->stripe] = env->spritecolor;
					y++;
				}
			}
		}
	}
} */

