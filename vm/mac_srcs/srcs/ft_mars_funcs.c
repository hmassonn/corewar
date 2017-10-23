/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mars_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:11:23 by clanier           #+#    #+#             */
/*   Updated: 2017/03/07 12:11:36 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_get_gap(t_cpu *cpu)
{
	int	gap;
	int	i;

	gap = MEM_SIZE;
	i = 0;
	while (cpu)
	{
		gap -= cpu->size;
		cpu = cpu->next;
		i++;
	}
	gap /= i;
	return (gap);
}

void	ft_fill_arena(t_mars *mars, t_cpu **cpu)
{
	int		gap;
	int		i;
	int		j;
	t_cpu	*lst;

	gap = ft_get_gap(*cpu);
	lst = *cpu;
	i = 0;
	while (lst)
	{
		j = 0;
		lst->pc = i;
		while (j < lst->size)
		{
			mars->arena[i] = lst->code[j];
			mars->arena_color[i] = lst->color;
			j++;
			i++;
		}
		lst = lst->next;
		i += gap;
		while (i % 64)
			i--;
	}
}

void	ft_get_players_uid(t_mars *mars, t_cpu *cpu)
{
	int	i;

	i = 0;
	while (cpu)
	{
		mars->players[i] = cpu->uid;
		i++;
		cpu = cpu->next;
	}
	while (i < 4)
		mars->players[i++] = mars->players[0];
}

t_mars	*ft_new_mars(t_cpu **cpu, char opt, int dump)
{
	t_mars	*mars;

	mars = (t_mars*)ft_memalloc(sizeof(t_mars));
	ft_bzero(mars->arena, MEM_SIZE * sizeof(unsigned char));
	ft_bzero(mars->arena_color, MEM_SIZE * sizeof(short int));
	ft_fill_arena(mars, cpu);
	mars->last_live = 0;
	mars->last_live_check = 0;
	mars->cycle = 0;
	mars->modif = true;
	mars->live_check = 0;
	mars->cycle_to_die = CYCLE_TO_DIE;
	mars->opt = opt;
	mars->dump = dump;
	mars->fat_buf_len = 0;
	ft_get_players_uid(mars, *cpu);
	if (opt & 2)
		ft_mlx_init(mars);
	return (mars);
}

void	ft_del_mars(t_mars *mars)
{
	if (mars->opt & 2)
		ft_mlx_exit(mars);
	free(mars);
}
