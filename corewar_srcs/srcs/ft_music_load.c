/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sound.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:47:51 by clanier           #+#    #+#             */
/*   Updated: 2017/03/07 17:03:36 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>
#include <sys/time.h>

void	ft_draw_loading_mars(t_mars **mars, int wait)
{
	int	i;
	int	j;
	int	ij;

	i = -1;
	ij = 0;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			if ((*mars)->arena_color[ij])
			{
				ft_draw_case(*mars, i, j,
						ft_get_color((*mars)->arena_color[ij]));
				usleep(wait);
			}
			++ij;
		}
		ft_flush(*mars);
	}
}

void	ft_play_sound(t_mars *mars)
{
	if (!(mars->sound = (t_sound*)malloc(sizeof(t_sound))))
		exit(EXIT_FAILURE);
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
	unsigned long long	epoch1;
	unsigned long long	epoch2;
	struct timeval		tv;

	(*mars)->total_size = 0;
	while (cpu)
	{
		(*mars)->total_size += cpu->size;
		cpu = cpu->next;
	}
	ft_play_sound(*mars);
	gettimeofday(&tv, NULL);
	epoch1 = (unsigned long long)(tv.tv_sec) * 1000 +
	(unsigned long long)(tv.tv_usec) / 1000;
	ft_draw_loading_mars(mars, 17000000 / (*mars)->total_size);
	gettimeofday(&tv, NULL);
	epoch2 = (unsigned long long)(tv.tv_sec) * 1000 +
	(unsigned long long)(tv.tv_usec) / 1000;
	epoch1 = epoch2 - epoch1;
	usleep((19700 - (int)epoch1) * 1000);
}
