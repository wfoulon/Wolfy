/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:53:27 by wfoulon           #+#    #+#             */
/*   Updated: 2018/02/28 12:53:30 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include <time.h>
# include <SDL.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define MOVESPEED (0.25)
# define ROTSPEED (0.04)

# define SOUND_1 "son/01_-_Wolfenstein_3D_-_DOS_-_Horst-Wessel-Lied.wav"
# define SOUND_MENU "son/menuopen.wav"
# define SOUND_SHOT "son/weaponshot.wav"
# define SOUND_STEP "son/steps1.wav"
# define SOUND_STEP2 "son/steps2.wav"
# define SOUND_MENU2 "son/menuover.wav"
# define SOUND_MENU3 "son/menubutton.wav"
# define RGB(r, g, b) (256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define SWIDTH 64
# define SHEIGHT 64
/* # define NUMSPRITES 2 */
# define FLOOR 1
# define SKY 2
/* # define SPRITE 3 */

/* typedef	struct			s_audio
{
	SDL_AudioSpec		audiospec;
	Uint8				*audiobuffer;
	Uint32				audiobufferlen;
	Uint32				audiolen;
	Uint32				audiopos;
	int					play;
	int					volume;
}						t_audio; */

typedef struct			s_steps
{
	SDL_AudioSpec		wavspec;
	Uint32				wavlength;
	Uint8				*wavbuffer;
	SDL_AudioDeviceID	device;
	SDL_AudioSpec		wavspec2;
	Uint32				wavlength2;
	Uint8				*wavbuffer2;
	SDL_AudioDeviceID	device2;
}						t_steps;

typedef struct			s_shots
{
	SDL_AudioSpec		wavspec;
	Uint32				wavlength;
	Uint8				*wavbuffer;
	SDL_AudioDeviceID	device;
}						t_shots;

typedef struct			s_effects
{
	SDL_AudioSpec		wavspec;
	Uint32				wavlength;
	Uint8				*wavbuffer;
	SDL_AudioDeviceID	device;
	SDL_AudioSpec		wavspec2;
	Uint32				wavlength2;
	Uint8				*wavbuffer2;
	SDL_AudioDeviceID	device2;
	SDL_AudioSpec		wavspec3;
	Uint32				wavlength3;
	Uint8				*wavbuffer3;
	SDL_AudioDeviceID	device3;
}						t_effects;

/* typedef struct			s_sprite
{
	double				x;
	double				y;
	int					texture;
}						t_sprite; */

typedef struct			s_menu
{
	SDL_Surface			*image;
	SDL_Texture			*menu;
	SDL_Rect			position;
}						t_menu;
typedef struct			s_floor
{
	double				floorxwall;
	double				floorywall;
	double				distwall;
	double				distplayer;
	double				currentdist;
	int					y;
	double				weight;
	double				currentfloorx;
	double				currentfloory;
	int					floortexx;
	int					floortexy;
	int					skytexx;
	int					skytexy;
	int					checkerboardpattern;
	int					floortexture;
	}						t_floor;

typedef struct			s_env
{
	t_floor				*floor;
	t_steps				*steps;
	t_shots				*shots;
	t_effects			*effects;
	/* t_audio				audio; */
	t_menu				*menus;
	SDL_Window			*screen;
	SDL_Renderer		*render;
	SDL_Event			events;
	char				*mapaddr;
	int					**worldmap;
	int					closeprog;
	int					resolutionw;
	int					resolutionh;
	double				olddirx;
	double				oldcamerax;
	double				frametime;
	int					fullscreen;
	double				time;
	double				oldtime;
	double				posx;
	double				posy;
	double				dirx;
	int					x;
	double				diry;
	int					stepscalc;
	double				camx;
	double				camy;
	int					x_max;
	int					mapx;
	int					mapy;
	double				raydirx;
	double				raydiry;
	double				camerax;
	double				sidedistx;
	double				sidedisty;
	double				deltadisty;
	double				deltadistx;
	SDL_Surface			*pistol;
	SDL_Texture			*tpistol;
	SDL_Surface			*walltiles;
	SDL_Texture			*twalltiles;
	SDL_Surface			*floortiles;
	SDL_Texture			*tfloortiles;
	SDL_Surface 		*guy;
	SDL_Texture 		*tguy;
	int					map;
	double				perpwalldist;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	int					lineheight;
	int					drawstart;
	int					drawend;
	int					color;
	int					r;
	int					g;
	int					b;
	int					mousex;
	int					up;
	int					down;
	int					right;
	int					left;
	const Uint8			*keystate;
	SDL_Surface			**wall;
	SDL_Surface			*sky;
	SDL_Surface			**sfloor;
	SDL_Surface			*ssky;
	SDL_Surface			*swall;
	/* SDL_Surface			*spritesur; */
	double				wallx;
	int					texx;
	int					test;
	Uint32				*pixels;
	Uint8				pxl[4];
	Uint8				pxlf[4];
	Uint8				pxls[4];
	/* Uint8				pxlsprite[4]; */
	SDL_PixelFormat		*format;
	SDL_Texture			*twall;
	SDL_Texture			*tmp;
	int					longmapx;
	int					longmapy;
	int					menu;
	int					menuset;
	int					shift;
	int					clic;
	int					soundclic;
	int					soundbutton;
	int					shot;
	/* double				spritex;
	double				spritey; */
	double				invdet;
	double				transformy;
	double				transformx;
	int					drawstarty;
	int					drawstartx;
	int					drawendy;
	int					drawendx;
	/* int					spriteheight;
	int					spritewidth;
	int					stripe;
	int					spritetex;
	int					spritetexy; */
	int					d;
	Uint32				spritecolor;
	double				*zbuffer;
	/* int					*spriteorder;
	double				*spritedistance;
	int					spritescreenx; */
    double              fog;
    int 				textnum;
}						t_env;

/* void					ft_sprites(t_env *env); */
/* void					ft_begin_sky(t_env *env, t_floor *floor, int x); */
void 					getrgb2(int color, t_env *env, int text);
int						ft_strnblen(char *str);
void					ft_calc_raycasting(t_env *env, int x);
void					ft_print_render(t_env *env);
void					ft_keyevent(t_env *env);
void					sdlthread(t_env *env);
void 					stepscalcs(t_env *env);
void					print_settings(t_env *env, int x, int y);
void					stepsound(t_env *env);
void					mouseclk(t_env *env);
void					soundshot(t_env *env);
void					ft_menuopen(t_env *env);
void					ft_weapon(t_env *env);
void					ft_minimap(t_env *env, int x, int y);
int						ft_checkmap(t_env *env, int key);
void					mouse_rot(t_env *env);
void					ft_cursor(t_env *env);
Uint32					get_pixel(SDL_Surface *surface, int x, int y);
void					ft_keyevent(t_env *env);
int						keyrelease(t_env *env);
void					raycasting(t_env *env, int x);
void					ft_exit(t_env *env);
int						keypress(t_env *env);
int						sdl_initenv(t_env *env);
void					get_resolution(t_env *env);
void					sdl_loop(t_env *env);
void					parse_map(t_env *env, int ymap);
void					ft_createpxl(t_env *env);
void					draw_texture(t_env *env, int x);
/* int						wolf_audio(t_audio *audio);
int						init_audio(t_audio *audio);
void					audiocallback(void *udata, Uint8 *stream, int len);
void					manage_key(t_env *env);
void					manage_volume(t_env *env); */
void					ft_menu(t_env *env);
void					ft_init_menu(t_env *env);
void					ft_menu_audio(t_env *env, int x, int y);
void        			ft_begin_floor(t_env *env, t_floor *floor, int x);
int 					wallstex(t_env *env);
void        			ft_floor_var(t_env *env, t_floor *floor);
void            		calc_floor(t_env *env, t_floor *floor);
void 					ft_str_error(t_env *e, char *str);
void					init_env4(t_env *env);
void					sdl_errors(t_env *env);

#endif
