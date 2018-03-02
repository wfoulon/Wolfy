/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:32:42 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:32:43 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void        getrgb2(int color, t_env *env, int text)
{
    if (text == FLOOR)
    {
        env->pxlf[2] = (color & 0xFF0000) >> 16;
        env->pxlf[1] = (color & 0xFF00) >> 8;
        env->pxlf[0] = (color & 0xFF);
    }
    else if (text == SKY)
    {
        env->pxls[0] = (color & 0xFF0000) >> 16;
        env->pxls[1] = (color & 0xFF00) >> 8;
        env->pxls[2] = (color & 0xFF);
    }
   /*  else if (text == SPRITE)
    {
        env->pxlsprite[0] = (color & 0xFF0000) >> 16;
        env->pxlsprite[1] = (color & 0xFF00) >> 8;
        env->pxlsprite[2] = (color & 0xFF);
    } */
}

void        ft_floor_var(t_env *env, t_floor *floor)
{
    if (env->side == 0 && env->raydirx > 0)
    {
        floor->floorxwall = env->mapx;
        floor->floorywall = env->mapy + env->wallx;
    }
    else if (env->side == 0 && env->raydirx < 0)
    {
        floor->floorxwall = env->mapx + 1.0;
        floor->floorywall = env->mapy + env->wallx;
    }
    else if (env->side == 1 && env->raydiry > 0)
    {
        floor->floorxwall = env->mapx + env->wallx;
        floor->floorywall = env->mapy;
    }
    else
    {
        floor->floorxwall = env->mapx + env->wallx;
        floor->floorywall = env->mapy + 1.0;
    }
    floor->distwall = env->perpwalldist;
    floor->distplayer = 0.0;
    if (env->drawend < 0)
        env->drawend = env->resolutionh;
    floor->y = env->drawend;
}

void            calc_floor(t_env *env, t_floor *floor)
{
    floor->currentdist = env->resolutionh / (2.0 * floor->y -
        env->resolutionh);
    floor->weight = (floor->currentdist - floor->distplayer) /
        (floor->distwall - floor->distplayer);
    floor->currentfloorx = floor->weight * floor->floorxwall +
        (1.0 - floor->weight) * env->posx;
    floor->currentfloory = floor->weight * floor->floorywall +
        (1.0 - floor->weight) * env->posy;
    floor->floortexx = (int)(floor->currentfloorx * env->sfloor[0]->w) %
        env->sfloor[0]->w;
    floor->floortexy = (int)(floor->currentfloory * env->sfloor[0]->h) %
        env->sfloor[0]->h;
    floor->skytexx = (int)(floor->currentfloorx * env->ssky->w / 5) %
        env->ssky->w;
    floor->skytexy = (int)(floor->currentfloory * env->ssky->h / 5) %
        env->ssky->h;
    floor->checkerboardpattern = ((int)(floor->currentfloorx) +
        (int)(floor->currentfloory)) % 2;
    if (floor->checkerboardpattern == 0)
        floor->floortexture = 0;
    else
        floor->floortexture = 0;
}

void            ft_begin_floor(t_env *env, t_floor *floor, int x)
{
    Uint32      couleur;
    double      fog;

    ft_floor_var(env, floor);
    while (floor->y < env->resolutionh)
    {
        calc_floor(env, floor);
        fog = 1 - (floor->currentdist / 10) * 1.2;
        fog = (fog < 0 ? 0 : fog);
        getrgb2(get_pixel(env->sfloor[floor->floortexture], floor->floortexx,
            floor->floortexy), env, FLOOR);
        couleur = RGB(fog * env->pxlf[0], fog * env->pxlf[1], fog *
            env->pxlf[2]);
        env->pixels[floor->y * env->resolutionw + x] = (couleur >> 1) &
            8355711;
        getrgb2(get_pixel(env->ssky, floor->skytexx, floor->skytexy), env, SKY);
        couleur = RGB(fog * env->pxls[0], fog * env->pxls[1], fog *
            env->pxls[2]);
        env->pixels[(env->resolutionh - floor->y) * env->resolutionw +
            x] = couleur;
        floor->y++;
    }
}
