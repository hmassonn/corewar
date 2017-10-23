/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skull_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:07:05 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/07 12:07:15 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_reset_line(t_mars *mars, int y)
{
	int	x;

	x = 0;
	usleep(50000);
	ft_flush(mars);
	while (x < 64)
		ft_draw_case(mars, y, x++, 0);
}

void	ft_reset_top_grid(t_mars *mars)
{
	ft_reset_line(mars, 0);
	ft_reset_line(mars, 1);
	ft_reset_line(mars, 2);
	ft_reset_line(mars, 3);
	ft_reset_line(mars, 4);
	ft_reset_line(mars, 5);
	ft_reset_line(mars, 6);
	ft_reset_line(mars, 7);
	ft_reset_line(mars, 8);
	ft_reset_line(mars, 9);
}

void	ft_reset_btm_grid(t_mars *mars)
{
	ft_reset_line(mars, 55);
	ft_reset_line(mars, 56);
	ft_reset_line(mars, 57);
	ft_reset_line(mars, 58);
	ft_reset_line(mars, 59);
	ft_reset_line(mars, 60);
	ft_reset_line(mars, 61);
	ft_reset_line(mars, 62);
	ft_reset_line(mars, 63);
}
