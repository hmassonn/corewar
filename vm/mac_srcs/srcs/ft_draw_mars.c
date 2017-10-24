/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:28:56 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/06 17:33:37 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_draw_case(t_mars *mars, int y, int x, int color)
{
	int	i;
	int	j;
	int	tmpx;

	y = y * 13 + 3;
	i = y + 8;
	j = x * 13 + 11;
	tmpx = x;
	while (y < i)
	{
		x = tmpx * 13 + 3;
		while (x < j)
		{
			ft_draw_pixel(mars, y, x, color);
			x++;
		}
		y++;
	}
}

int		ft_get_color(int arena_color)
{
	if (arena_color < 0)
		arena_color %= 5;
	if (arena_color == 1)
		return (0x00ff00);
	else if (arena_color == 2)
		return (0x0000ff);
	else if (arena_color == 3)
		return (0xff0000);
	else if (arena_color == 4)
		return (0xff00ff);
	else if (arena_color == -1)
		return (0x006600);
	else if (arena_color == -2)
		return (0x000066);
	else if (arena_color == -3)
		return (0x660000);
	else if (arena_color == -4)
		return (0x660066);
	return (0);
}

void	ft_draw_mars(t_mars **mars, t_cpu *cpu)
{
	int		i;
	int		j;
	int		ij;
	char	pc[MEM_SIZE];

	ft_bzero(pc, MEM_SIZE);
	while (cpu)
	{
		if (cpu->live >= 0)
			pc[cpu->pc % MEM_SIZE] = 1;
		cpu = cpu->next;
	}
	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			ij = i * 64 + j;
			if ((*mars)->arena_color[ij])
				ft_draw_case(*mars, i, j, pc[ij] ? 0xffffff
						: ft_get_color((*mars)->arena_color[ij]));
		}
	}
}

void	ft_draw_info(t_mars **mars)
{
	char	*cycle;
	char	*cycle_to_die;
	char	*process;

	cycle = ft_itoa((*mars)->cycle);
	cycle_to_die = ft_itoa((*mars)->cycle_to_die);
	process = ft_itoa((*mars)->process);
	mlx_string_put((*mars)->mlx->mlx, (*mars)->mlx->win,
			X_MAP + 65, 40, 0xffffff, "Cycle         :");
	mlx_string_put((*mars)->mlx->mlx, (*mars)->mlx->win,
			X_MAP + 210, 40, 0xffffff, cycle);
	mlx_string_put((*mars)->mlx->mlx, (*mars)->mlx->win,
			X_MAP + 65, 90, 0xffffff, "Cycle to die  :");
	mlx_string_put((*mars)->mlx->mlx, (*mars)->mlx->win,
			X_MAP + 210, 90, 0xffffff, cycle_to_die);
	mlx_string_put((*mars)->mlx->mlx, (*mars)->mlx->win,
			X_MAP + 65, 140, 0xffffff, "Process       :");
	mlx_string_put((*mars)->mlx->mlx, (*mars)->mlx->win,
			X_MAP + 210, 140, 0xffffff, process);
	free(cycle);
	free(cycle_to_die);
	free(process);
}

void	ft_refresh_mars(t_mars **mars, t_cpu *cpu)
{
	ft_draw_mars(mars, cpu);
	ft_flush(*mars);
	ft_draw_info(mars);
	usleep(10000);
}
