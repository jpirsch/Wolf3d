/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 11:46:06 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/02 15:19:23 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

void	shoot(t_env *e)
{
	SDL_SetRenderDrawColor(e->rend, 255, 0, 0, 0);
	SDL_RenderClear(e->rend);
	SDL_RenderPresent(e->rend);
	play_sound(e);
}
