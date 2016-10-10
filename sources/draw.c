/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 05:13:47 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/02 13:11:03 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "libft.h"
#include "wolf.h"

static void	draw_vertical(t_env *e, t_point start, t_point end, int i)
{
	if (start.y < 0)
		start.y = 0;
	if (end.y > e->h)
		end.y = e->h;
	while (start.y + i < end.y)
	{
		draw_point(e, start.x, start.y + i);
		i++;
	}
	i = 0;
	while (i < start.y)
	{
		(i / 3 < 125) ? SDL_SetRenderDrawColor(e->rend, 50, 70, 120 + i / 3, 0)
			: SDL_SetRenderDrawColor(e->rend, 50, 70, 255, 0);
		draw_point(e, start.x, i);
		i++;
	}
	i = 0;
	SDL_SetRenderDrawColor(e->rend, 90, 90, 90, 0);
	while (end.y + i < e->h)
	{
		draw_point(e, start.x, end.y + i);
		i++;
	}
}

static void	color(t_env *e, t_play *p, int i)
{
	t_point	start;
	t_point	end;

	start.x = i;
	start.y = (e->h / 2) - (p->hmur / 2);
	end.x = i;
	end.y = (e->h / 2) + (p->hmur / 2);
	if (p->mvh == 0)
	{
		(p->mapx > e->cam.posx) ? SDL_SetRenderDrawColor(e->rend, 0, 64, 200, 0)
		: SDL_SetRenderDrawColor(e->rend, 200, 64, 0, 0);
	}
	else
	{
		(p->mapy > e->cam.posy) ? SDL_SetRenderDrawColor(e->rend, 0, 200, 64, 0)
			: SDL_SetRenderDrawColor(e->rend, 255, 64, 0, 0);
	}
	draw_vertical(e, start, end, 0);
}

static void	colone(t_env *e, t_play *p, int i)
{
	while (e->map[p->mapy][p->mapx] == 0)
	{
		if (p->distmurx < p->distmury)
		{
			p->distmurx += p->dist2murx;
			p->mapx += p->erx;
			p->mvh = 0;
		}
		else
		{
			p->distmury += p->dist2mury;
			p->mapy += p->ery;
			p->mvh = 1;
		}
	}
	if (p->mvh == 0)
		p->longmur = fabs((p->mapx - p->raypx + (1 - p->erx) / 2) / p->raydx);
	else
		p->longmur = fabs((p->mapy - p->raypy + (1 - p->ery) / 2) / p->raydy);
	p->hmur = abs((int)(e->h / p->longmur));
	color(e, p, i);
}

static void	get_d(t_env *e, int i, t_play p)
{
	while (i < e->w)
	{
		if (i % 2 == 0)
		{
			p.camerax = 2 * i / (double)(e->w) - 1;
			p.raypx = e->cam.posx;
			p.raypy = e->cam.posy;
			p.raydx = e->cam.dirx + e->cam.planx * p.camerax;
			p.raydy = e->cam.diry + e->cam.plany * p.camerax;
			p.mapx = (int)p.raypx;
			p.mapy = (int)p.raypy;
			p.dist2murx = sqrt(1 + (p.raydy * p.raydy) / (p.raydx * p.raydx));
			p.dist2mury = sqrt(1 + (p.raydx * p.raydx) / (p.raydy * p.raydy));
			p.touche = 0;
			if (p.raydx < 0 && (p.erx = -1))
				p.distmurx = (p.raypx - p.mapx) * p.dist2murx;
			else if ((p.erx = 1))
				p.distmurx = (p.mapx + 1.0 - p.raypx) * p.dist2murx;
			if (p.raydy < 0 && (p.ery = -1))
				p.distmury = (p.raypy - p.mapy) * p.dist2mury;
			else if ((p.ery = 1))
				p.distmury = (p.mapy + 1.0 - p.raypy) * p.dist2mury;
		}
		colone(e, &p, ++i);
	}
}

void		draw(t_env *e)
{
	t_play p;

	p.mvh = 0;
	SDL_SetRenderDrawColor(e->rend, 0, 0, 0, 0);
	SDL_RenderClear(e->rend);
	get_d(e, 0, p);
	put_sprite(e);
	SDL_RenderPresent(e->rend);
}
