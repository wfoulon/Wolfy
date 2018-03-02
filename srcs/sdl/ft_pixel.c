/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:35:04 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:35:06 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void setPixel(t_env *env, Uint8 pxl[4], size_t x)
{
    Uint32 couleur;
	
	env->fog = 1 - (env->perpwalldist / 10) * 1.2;
	env->fog = (env->fog < 0 ? 0 : env->fog);
	couleur = RGB(env->fog * pxl[0], env->fog * pxl[1], env->fog * pxl[2]);
    env->pixels[env->drawstart * env->resolutionw + x] = couleur;
}

Uint32 get_pixel(SDL_Surface *surface, int x, int y)
{
    Uint32 *p;

    p = surface->pixels + y * surface->pitch + x * 4;
   /*  if (surface->format->BytesPerPixel == 1)
        return (*p);
    else if (surface->format->BytesPerPixel == 2)
        return (*(Uint16 *)p);
    else if (surface->format->BytesPerPixel == 3)
    {
        if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return (p[0] << 16 | p[1] << 8 | p[2]);
        else
            return (p[0] | p[1] << 8 | p[2] << 16);
    }
    else if (surface->format->BytesPerPixel == 4)
        return (*(Uint32 *)p); */
    return (*p);
}

void ft_createpxl(t_env *env)
{
	free(env->pixels);
	if (!(env->pixels = (Uint32 *)malloc(sizeof(Uint32) * env->resolutionw *
								   env->resolutionh + 4)))
            ft_str_error(env, "MALLOC FAILURE : PIXEL CREATION");
	
}

void                getrgb(int color, t_env *env)
{
/*     env->pxl[(env->mapx % 2 == 0) && (env->mapy % 2 == 0) ? 0 : 2] = (color & 0xFF);
    env->pxl[1] = (color & 0xFF00) >> 8;
    env->pxl[(env->mapx % 2 == 0) && (env->mapy % 2 == 0) ? 2 : 0] = (color & 0xFF0000) >> 16; */
    env->pxl[(env->mapx == 0 || env->mapx == env->longmapy - 1 ||
        env->mapy == 0 || env->longmapx - 1 == env->mapy) ? 0 : 2] =
        (color & 0xFF0000) >> 16;
    env->pxl[1] = (color & 0xFF00) >> 8;
    env->pxl[(env->mapx == 0 || env->mapx == env->longmapy - 1 ||
        env->mapy == 0 || env->longmapx - 1 == env->mapy) ? 2 : 0] =
        (color & 0xFF);
}

void				draw_texture(t_env *env, int x)
{
    int y;

    y = (env->drawstart * 2 - env->resolutionh + env->lineheight) *
        (env->wall[env->textnum]->h / 2) / env->lineheight;
    getrgb(get_pixel(env->wall[env->textnum], env->texx, (int)y), env
               /*  env->wall->format,
                &(env->pxl[0]), &(env->pxl[1]), &(env->pxl[2]) */);
   SDL_UnlockSurface(env->wall[env->textnum]);
    setPixel(env, env->pxl, x);
}

/* int     wallstex(t_env *env)
{
   if (env->raydirx > 0)
       return (2);
   else if (env->raydiry < 0)
       return (3);
   else if (env->side == 0)
       return (0);
   else if (env->side == 1)
       return (1);
   return (0);
} */
