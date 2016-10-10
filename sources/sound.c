/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 18:47:53 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/02 16:55:22 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL/SDL.h"
#include "libft.h"
#include "wolf.h"

void	load_sound(t_env *e, char *path)
{
	if ((SDL_LoadWAV(path, &e->wav_spec, &e->wav_buffer,
		&e->wav_length)) == NULL)
	{
		ft_putendl_fd((char*)SDL_GetError(), 2);
		exit(-1);
	}
	e->wav_spec.callback = my_audio_callback;
	e->audio_pos = e->wav_buffer;
	e->wav_spec.userdata = e;
	e->audio_len = e->wav_length;
	if (SDL_OpenAudio(&e->wav_spec, NULL) < 0)
	{
		ft_putendl_fd((char*)SDL_GetError(), 2);
		exit(-1);
	}
}

void	my_audio_callback(void *userdata, Uint8 *stream, int len)
{
	t_env *e;

	e = (t_env*)userdata;
	if (e->audio_len == 0)
		return ;
	if ((Uint32)len > e->audio_len)
		len = e->audio_len;
	SDL_memcpy(stream, e->audio_pos, len);
	SDL_MixAudio(stream, e->audio_pos, len, SDL_MIX_MAXVOLUME);
	e->audio_pos += len;
	e->audio_len -= len;
}

int		play_sound(t_env *e)
{
	e->audio_pos = e->wav_buffer;
	e->audio_len = e->wav_length;
	SDL_PauseAudio(0);
	while (e->audio_len > e->wav_length - (e->wav_length / 5))
		SDL_Delay(100);
	SDL_PauseAudio(1);
	return (0);
}
