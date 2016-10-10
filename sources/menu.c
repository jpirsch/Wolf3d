/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 12:25:54 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/02 17:31:49 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf.h"

void	menu(t_env *e)
{
	SDL_Rect	dest;

	SDL_SetRenderDrawColor(e->rend, 0, 0, 0, 0);
	SDL_RenderClear(e->rend);
	if (e->texture)
	{
		dest.x = (e->w - (e->sprite->w + e->w) / 4) / 2;
		dest.y = (e->sprite->h + e->h) / 4;
		dest.w = (e->sprite->w + e->w) / 4;
		dest.h = (e->sprite->h + e->h) / 4;
		SDL_SetTextureBlendMode(e->texture, SDL_BLENDMODE_BLEND);
		SDL_RenderCopy(e->rend, e->texture, NULL, &dest);
	}
	else
		ft_putendl_fd((char*)SDL_GetError(), 2);
	SDL_RenderPresent(e->rend);
}

int		menu_event(t_env *e)
{
	int	x;
	int	y;

	x = (e->w - (e->sprite->w + e->w) / 4) / 2;
	y = (e->sprite->h + e->h) / 4;
	if (e->event.type == SDL_MOUSEBUTTONDOWN)
		if (e->event.button.button == SDL_BUTTON_LEFT)
			if (e->event.button.x > x &&
				e->event.button.x < x + (e->sprite->w + e->w) / 4 &&
				e->event.button.y > y &&
				e->event.button.y < y + (e->sprite->h + e->h) / 4)
				e->r = 255;
	return ((e->r == 255) ? 1 : 0);
}
