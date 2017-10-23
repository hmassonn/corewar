/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sound.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:47:51 by clanier           #+#    #+#             */
/*   Updated: 2017/03/07 11:48:51 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	ft_draw_loading_mars(t_mars **mars, int wait)
{
	int	i;
	int	j;
	int	ij;
	int	draw;

	i = -1;
	(void)wait;
	while (++i < 64 && !(draw = 0))
	{
		j = -1;
		while (++j < 64)
		{
			ij = i * 64 + j;
			if ((*mars)->arena_color[ij] && (draw = 1))
			{
				ft_draw_case(*mars, i, j,
				ft_get_color((*mars)->arena_color[ij]));
				usleep(wait);
			}
		}
		ft_flush(*mars);
	}
}

void	ft_play_sound(t_mars *mars)
{
	mars->sound = (t_sound*)malloc(sizeof(t_sound));
	mars->sound->system = NULL;
	FMOD_System_Create(&mars->sound->system);
	FMOD_System_Init(mars->sound->system, 2, FMOD_INIT_NORMAL, NULL);
	FMOD_System_CreateSound(mars->sound->system, "music/starfish.mp3",
	FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0, &mars->sound->sound);
	FMOD_Sound_SetLoopCount(mars->sound->sound, -1);
	FMOD_System_PlaySound(mars->sound->system,
	FMOD_CHANNEL_FREE, mars->sound->sound, 0, NULL);
	FMOD_System_GetMasterChannelGroup(mars->sound->system,
	&mars->sound->channelgroup);
}

void	ft_music_load(t_mars **mars, t_cpu *cpu)
{
	(*mars)->total_size = 0;
	while (cpu)
	{
		(*mars)->total_size += cpu->size;
		cpu = cpu->next;
	}
	ft_flush(*mars);
	ft_play_sound(*mars);
	ft_draw_loading_mars(mars, 18200000 / (*mars)->total_size);
	usleep(300000);
}
