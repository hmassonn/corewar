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
