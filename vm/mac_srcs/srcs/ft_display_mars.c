/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_mars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:28:59 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/06 17:29:08 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_display_mars(t_mars **mars, t_cpu *cpu)
{
	if ((*mars)->opt & 1)
		ft_print_mars(mars, cpu);
	else if ((*mars)->opt & 2)
		ft_refresh_mars(mars, cpu);
	usleep(10000);
	(*mars)->modif = false;
}
