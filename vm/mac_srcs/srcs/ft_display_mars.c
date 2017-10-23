/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_mars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:01:54 by clanier           #+#    #+#             */
/*   Updated: 2017/03/07 12:01:57 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_display_mars(t_mars **mars, t_cpu *cpu)
{
	if ((*mars)->opt & 0b00000001)
		ft_print_mars(mars, cpu);
	else if ((*mars)->opt & 0b00000010)
		ft_refresh_mars(mars, cpu);
	else if ((*mars)->opt & 0b00000100)
		ft_ncurses_mars(*mars, cpu);
	usleep(10000);
	(*mars)->modif = false;
}
