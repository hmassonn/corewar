#include "corewar.h"

void	ft_draw_case_line(t_mars *mars, int x1, int x2, int y)
{
	static int	last_y = 0;
	int		swap;

	if (last_y != y)
		ft_reset_line(mars, y);
	last_y = y;
	if (x1 > x2)
	{
		swap = x1;
		x1 = x2;
		x2 = swap;
	}
	while (x1 <= x2)
		ft_draw_case(mars, y, x1++, mars->last_live);
}

void	ft_draw_skull_1(t_mars *mars)
{
	ft_draw_case_line(mars, 29, 34, 10);
	ft_draw_case_line(mars, 26, 37, 11);
	ft_draw_case_line(mars, 23, 40, 12);
	ft_draw_case_line(mars, 22, 41, 13);
	ft_draw_case_line(mars, 20, 43, 14);
	ft_draw_case_line(mars, 19, 44, 15);
	ft_draw_case_line(mars, 19, 44, 16);
	ft_draw_case_line(mars, 18, 45, 17);
	ft_draw_case_line(mars, 17, 46, 18);
	ft_draw_case_line(mars, 17, 46, 19);
	ft_draw_case_line(mars, 17, 46, 20);
	ft_draw_case_line(mars, 16, 47, 21);
	ft_draw_case_line(mars, 16, 47, 22);
	ft_draw_case_line(mars, 15, 48, 23);
	ft_draw_case_line(mars, 15, 48, 24);
	ft_draw_case_line(mars, 15, 48, 25);
	ft_draw_case_line(mars, 15, 48, 26);
	ft_draw_case_line(mars, 16, 47, 27);
	ft_draw_case_line(mars, 16, 20, 28);
	ft_draw_case_line(mars, 28, 35, 28);
	ft_draw_case_line(mars, 43, 47, 28);
	ft_draw_case_line(mars, 16, 19, 29);
	ft_draw_case_line(mars, 30, 33, 29);
	ft_draw_case_line(mars, 44, 47, 29);
}

void	ft_draw_skull_2(t_mars *mars)
{
	ft_draw_case_line(mars, 16, 18, 30);
	ft_draw_case_line(mars, 30, 33, 30);
	ft_draw_case_line(mars, 45, 47, 30);
	ft_draw_case_line(mars, 17, 18, 31);
	ft_draw_case_line(mars, 29, 34, 31);
	ft_draw_case_line(mars, 45, 46, 31);
	ft_draw_case_line(mars, 17, 18, 32);
	ft_draw_case_line(mars, 29, 34, 32);
	ft_draw_case_line(mars, 45, 46, 32);
	ft_draw_case_line(mars, 17, 19, 33);
	ft_draw_case_line(mars, 29, 30, 33);
	ft_draw_case_line(mars, 33, 34, 33);
	ft_draw_case_line(mars, 44, 46, 33);
	ft_draw_case_line(mars, 18, 19, 34);
	ft_draw_case_line(mars, 28, 30, 34);
	ft_draw_case_line(mars, 33, 35, 34);
	ft_draw_case_line(mars, 44, 45, 34);
	ft_draw_case_line(mars, 17, 20, 35);
	ft_draw_case_line(mars, 26, 29, 35);
	ft_draw_case_line(mars, 34, 37, 35);
	ft_draw_case_line(mars, 43, 46, 35);
	ft_draw_case_line(mars, 17, 28, 36);
	ft_draw_case_line(mars, 35, 46, 36);
	ft_draw_case_line(mars, 16, 27, 37);
	ft_draw_case_line(mars, 36, 47, 37);
}

void	ft_draw_skull_3(t_mars *mars)
{
	ft_draw_case_line(mars, 16, 27, 38);
	ft_draw_case_line(mars, 31, 32, 38);
	ft_draw_case_line(mars, 36, 47, 38);
	ft_draw_case_line(mars, 16, 26, 39);
	ft_draw_case_line(mars, 30, 33, 39);
	ft_draw_case_line(mars, 37, 47, 39);
	ft_draw_case_line(mars, 17, 27, 40);
	ft_draw_case_line(mars, 30, 33, 40);
	ft_draw_case_line(mars, 36, 46, 40);
	ft_draw_case_line(mars, 21, 42, 41);
	ft_draw_case_line(mars, 22, 23, 42);
	ft_draw_case_line(mars, 25, 26, 42);
	ft_draw_case_line(mars, 28, 28, 42);
	ft_draw_case_line(mars, 31, 32, 42);
	ft_draw_case_line(mars, 35, 35, 42);
	ft_draw_case_line(mars, 37, 38, 42);
	ft_draw_case_line(mars, 40, 41, 42);
	ft_draw_case_line(mars, 22, 23, 43);
	ft_draw_case_line(mars, 25, 25, 43);
	ft_draw_case_line(mars, 28, 28, 43);
	ft_draw_case_line(mars, 31, 32, 43);
	ft_draw_case_line(mars, 35, 35, 43);
	ft_draw_case_line(mars, 38, 38, 43);
	ft_draw_case_line(mars, 40, 41, 43);
}

void	ft_draw_skull_4(t_mars *mars)
{
	ft_draw_case_line(mars, 21, 23, 44);
	ft_draw_case_line(mars, 40, 42, 44);
	ft_draw_case_line(mars, 21, 23, 45);
	ft_draw_case_line(mars, 26, 26, 45);
	ft_draw_case_line(mars, 37, 37, 45);
	ft_draw_case_line(mars, 40, 42, 45);
	ft_draw_case_line(mars, 21, 24, 46);
	ft_draw_case_line(mars, 26, 26, 46);
	ft_draw_case_line(mars, 28, 28, 46);
	ft_draw_case_line(mars, 31, 32, 46);
	ft_draw_case_line(mars, 35, 35, 46);
	ft_draw_case_line(mars, 37, 37, 46);
	ft_draw_case_line(mars, 39, 42, 46);
	ft_draw_case_line(mars, 21, 26, 47);
	ft_draw_case_line(mars, 28, 28, 47);
	ft_draw_case_line(mars, 31, 32, 47);
	ft_draw_case_line(mars, 35, 35, 47);
	ft_draw_case_line(mars, 37, 42, 47);
	ft_draw_case_line(mars, 21, 42, 48);
	ft_draw_case_line(mars, 21, 42, 49);
	ft_draw_case_line(mars, 22, 41, 50);
	ft_draw_case_line(mars, 24, 39, 51);
	ft_draw_case_line(mars, 25, 38, 52);
	ft_draw_case_line(mars, 27, 36, 53);
	ft_draw_case_line(mars, 30, 33, 54);
}
