/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 05:07:55 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/02 17:33:01 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf.h"

static void		init_cam(t_cam *cam)
{
	cam->posx = 6;
	cam->posy = 6;
	cam->dirx = -1;
	cam->diry = 0;
	cam->planx = 0;
	cam->plany = 0.66;
}

static void		init_keys(t_env *e)
{
	e->k.esc = 0;
	e->k.up = 0;
	e->k.down = 0;
	e->k.left = 0;
	e->k.right = 0;
	e->k.a = 0;
	e->k.d = 0;
	e->k.mouse = 0;
}

static t_env	*init_env(int **map)
{
	t_env *e;

	e = (t_env*)malloc(sizeof(t_env) * 1);
	ft_init_sdl(e);
	ft_create_win_sdl(e, 0, 0);
	e->rend = ft_init_renderer(e);
	e->map = map;
	init_cam(&e->cam);
	init_keys(e);
	load_image(e, "ressources/menu.bmp");
	load_sound(e, "ressources/test.wav");
	return (e);
}

void			menu_loop(t_env *e)
{
	int		start;

	start = 0;
	while (start != 1)
	{
		while (SDL_PollEvent(&e->event))
		{
			SDL_GetWindowSize(e->win_sdl, &e->w, &e->h);
			start = menu_event(e);
			menu(e);
		}
	}
	if (e->texture)
		SDL_DestroyTexture(e->texture);
	if (e->sprite)
		SDL_FreeSurface(e->sprite);
	load_image(e, GUN);
}

int				sdl_env(int **map)
{
	t_env	*e;

	if (map == NULL)
		return (0);
	e = init_env(map);
	menu_loop(e);
	while (1)
	{
		while (SDL_PollEvent(&e->event))
		{
			SDL_GetWindowSize(e->win_sdl, &e->w, &e->h);
			handle_event(e);
			draw(e);
		}
	}
	if (ft_free(e))
		return (1);
	else
		return (0);
}
