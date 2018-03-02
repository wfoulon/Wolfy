/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:33:09 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:33:11 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/* void ft_begin_sky(t_env *env, t_floor *floor, int x)
{
    if (env->side == 0 && env->raydirx < 0)
    {
        floor->floorxwall = env->mapx;
        floor->floorywall = env->mapy + env->wallx;
    }
    else if (env->side == 0 && env->raydirx > 0)
    {
        floor->floorxwall = env->mapx + 1.0;
        floor->floorywall = env->mapy + env->wallx;
    }
    else if (env->side == 1 && env->raydiry < 0)
    {
        floor->floorxwall = env->mapx + env->wallx;
        floor->floorywall = env->mapy;
    }
    else
    {
        floor->floorxwall = env->mapx + env->wallx;
        floor->floorywall = env->mapy + 1.0;
    }
    //
    floor->distwall = env->perpwalldist;
    floor->distplayer = 0.0;
     if (env->drawend < 0)
        env->drawend = env->resolutionh;
    floor->y = 0;
    while (floor->y <= env->drawstart)
    {
        floor->currentdist = env->resolutionh / (2.0 * floor->y - env->resolutionh);
        floor->weight = (floor->currentdist - floor->distplayer) / (floor->distwall - floor->distplayer);
        floor->currentfloorx = floor->weight * floor->floorxwall + (1.0 - floor->weight) * env->posx;
        floor->currentfloory = floor->weight * floor->floorywall + (1.0 - floor->weight) * env->posy;
        floor->floortexx = (int)(floor->currentfloorx * env->ssky->w / 10) % env->ssky->w;
        floor->floortexy = (int)(floor->currentfloory * env->ssky->h / 10) % env->ssky->h;
        floor->checkerboardpattern = ((int)(floor->currentfloorx + floor->currentfloory)) % 2;
        if (floor->checkerboardpattern == 0)
            floor->floortexture = 3;
        else
            floor->floortexture = 4;
        getrgb2(get_pixel(env->ssky, floor->floortexx, floor->floortexy), env, SKY);
        Uint32 couleur;
        couleur = RGB(env->pxls[0], env->pxls[1], env->pxls[2]);
        //env->pxlf = (Uint32)(env->sfloor->pixels[env->sfloor->w * floor->floortexy + floor->floortexx]);
        env->pixels[floor->y * env->resolutionw + x] = couleur;
        floor->y++;
    }
} */
