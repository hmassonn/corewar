/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:03:28 by clanier           #+#    #+#             */
/*   Updated: 2017/03/07 12:03:46 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_flush(t_mars *mars)
{
	static int	i = 0;

	mlx_put_image_to_window(mars->mlx->mlx,
	mars->mlx->win, mars->mlx->img, 0, 0);
	if (i)
		glFlush();
	else if ((i = 1))
		mlx_do_sync(mars->mlx->mlx);
}

void	ft_draw_pixel(t_mars *mars, int y, int x, int color)
{
	int	i;

	if (y >= Y_WIN || y < 0 || x >= X_WIN || x < 0)
		return ;
	i = mars->mlx->sl * y + x * 4;
	mars->mlx->data[i] = color & 0xff;
	mars->mlx->data[++i] = color >> 8 & 0xff;
	mars->mlx->data[++i] = color >> 16;
}

void	ft_draw_grid(t_mars *mars)
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

void	ft_mlx_init(t_mars *mars)
{
	int	bpp;
	int	endian;

	mars->mlx = (t_mlx*)malloc(sizeof(t_mars));
	mars->mlx->mlx = mlx_init();
	mars->mlx->win = mlx_new_window(mars->mlx->mlx,
	X_WIN, Y_WIN, "COREWAR\tby \"alphacore\"");
	mars->mlx->img = mlx_new_image(mars->mlx->mlx, X_WIN, Y_WIN);
	mars->mlx->data = mlx_get_data_addr(mars->mlx->img,
	&bpp, &mars->mlx->sl, &endian);
	ft_draw_grid(mars);
}

void	ft_mlx_exit(t_mars *mars)
{
	mlx_destroy_image(mars->mlx->mlx, mars->mlx->img);
	mlx_destroy_window(mars->mlx->mlx, mars->mlx->win);
	free(mars->mlx->mlx);
	free(mars->mlx);
}
