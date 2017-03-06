/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:27:20 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/06 17:27:34 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_draw_pixel(t_mars *mars, int y, int x, int color)
{
	int	i;

	if (y >= Y_WIN || y < 0 || x >= X_WIN || x < 0)
		return ;
	i = mars->mlx->sl * y + x * 4;
	mars->mlx->data[i] = color & 0xff;
	mars->mlx->data[++i] = color >> 8 & 0xff;
	mars->mlx->data[++i] = color >> 16;
}

void		ft_new_image(t_mars *mars)
{
	int	bpp;
	int	endian;

	mars->mlx->img = mlx_new_image(mars->mlx->mlx, X_WIN, Y_WIN);
	mars->mlx->data = mlx_get_data_addr(mars->mlx->img,
			&bpp, &mars->mlx->sl, &endian);
}

void		ft_draw_grid(t_mars *mars)
{
	int	i;
	int	j;

	i = 0;
	while (i < Y_MAP)
	{
		j = 0;
		while (j < X_MAP)
		{
			ft_draw_pixel(mars, i, j, 0xffffff);
			j += !(i % 13) ? 1 : 13;
		}
		i++;
	}
}

void		ft_mlx_init(t_mars *mars)
{
	mars->mlx = (t_mlx*)malloc(sizeof(t_mars));
	mars->mlx->mlx = mlx_init();
	mars->mlx->win = mlx_new_window(mars->mlx->mlx,
			X_WIN, Y_WIN, "COREWAR\tby \"alphacore\"");
	ft_new_image(mars);
	ft_draw_grid(mars);
}

void		ft_mlx_exit(t_mars *mars)
{
	mlx_destroy_image(mars->mlx->mlx, mars->mlx->img);
	mlx_destroy_window(mars->mlx->mlx, mars->mlx->win);
	free(mars->mlx->mlx);
	free(mars->mlx);
}
