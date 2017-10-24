/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:28:39 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/06 17:28:46 by hmassonn         ###   ########.fr       */
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
