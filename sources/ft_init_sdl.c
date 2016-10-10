/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 11:26:17 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/01 19:13:28 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf.h"

int				ft_free(t_env *e)
{
	int i;

	i = 0;
	while (i < e->map[0][0])
	{
		free(e->map[i]);
		i++;
	}
	if (e->texture)
		SDL_DestroyTexture(e->texture);
	if (e->sprite)
		SDL_FreeSurface(e->sprite);
	if (e->rend)
		SDL_DestroyRenderer(e->rend);
	if (e->win_sdl)
		SDL_DestroyWindow(e->win_sdl);
	SDL_CloseAudio();
	SDL_FreeWAV(e->wav_buffer);
	SDL_Quit();
	return (1);
}

void			ft_init_sdl(t_env *e)
{
	if (SDL_Init(SDL_INIT_FLAGS | SDL_INIT_AUDIO) < 0)
	{
		ft_putstr_fd("SDL_Init error ", 2);
		ft_putendl_fd((char*)SDL_GetError(), 2);
		ft_free(e);
		exit(-1);
	}
}

void			ft_create_win_sdl(t_env *e, int w, int h)
{
	if (w <= 0 || h <= 0)
	{
		if ((e->win_sdl = SDL_CreateWindow(NAME, POS_X, POS_Y, POS_WIDTH, \
						POS_HEIGHT, SDL_WIN_FLAGS)) == NULL)
		{
			ft_putstr_fd("SDL_CreateWindow error ", 2);
			ft_putendl_fd((char*)SDL_GetError(), 2);
			ft_free(e);
			exit(-1);
		}
	}
	else
	{
		if ((e->win_sdl = SDL_CreateWindow(NAME, POS_X, POS_Y, w, \
						h, SDL_WIN_FLAGS)) == NULL)
		{
			ft_putstr_fd("SDL_CreateWindow error ", 2);
			ft_putendl_fd((char*)SDL_GetError(), 2);
			ft_free(e);
			exit(-1);
		}
	}
}

SDL_Renderer	*ft_init_renderer(t_env *e)
{
	SDL_Renderer *g_renderer;

	if ((g_renderer = SDL_CreateRenderer(e->win_sdl, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
			== NULL)
	{
		ft_putstr_fd("SDL_Create_Renderer error ", 2);
		ft_putendl_fd((char*)SDL_GetError(), 2);
		ft_free(e);
		exit(-1);
	}
	return (g_renderer);
}
