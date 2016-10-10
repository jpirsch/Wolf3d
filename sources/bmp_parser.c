/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 01:11:40 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/02 16:53:28 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf.h"

void	load_image(t_env *e, char *text_path)
{
	Uint32 colorkey;

	e->sprite = SDL_LoadBMP(text_path);
	if (e->sprite)
	{
		colorkey = SDL_MapRGB(e->sprite->format, 0, 0, 0);
		SDL_SetColorKey(e->sprite, SDL_TRUE, colorkey);
		e->texture = SDL_CreateTextureFromSurface(e->rend, e->sprite);
	}
	else
		ft_putendl_fd((char*)SDL_GetError(), 2);
}

void	put_sprite(t_env *e)
{
	SDL_Rect	dest;

	if (e->texture)
	{
		dest.x = (e->w - (e->sprite->w + e->w) / 8) / 2;
		dest.y = e->h - (e->sprite->h + e->h) / 8;
		dest.w = (e->sprite->w + e->w) / 8;
		dest.h = (e->sprite->h + e->h) / 8;
		SDL_SetTextureBlendMode(e->texture, SDL_BLENDMODE_BLEND);
		SDL_RenderCopy(e->rend, e->texture, NULL, &dest);
	}
	else
		ft_putendl_fd((char*)SDL_GetError(), 2);
}
