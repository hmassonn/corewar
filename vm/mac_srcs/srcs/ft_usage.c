/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:58:59 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/06 16:59:53 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_helper(void)
{
	ft_printf("\nusage: ./corewar [OPTIONS] [CHAMPIONS]\n\
	-g              : graphic visualisation mode\n\
	-p              : basic visualisation mode\n\
	-q              : quiet mode (for lives)\n\
	-v              : verbose mode (for cycles and cycle to die)\n\
	-dump nbr_cycle : dump the arena at nbr_cycle precise\n\
	-n nbr          : to give \"nbr\" as number for the following player\n\
	-c              : basic informations with basic visualisation mode\n");
}

int		ft_bad_usage(t_cpu **cpu, int ac)
{
	ft_printf("{red}{bold}[COREWAR]{eoc} too %s ", ac > 4 ? "many" : "few");
	ft_printf("parameters to call the virtual machine\n");
	ft_helper();
	ft_del_cpu(cpu);
	return (0);
}

int		ft_player_error(t_cpu **cpu, char *name, int fd)
{
	if (fd)
		close(fd);
	ft_printf("{red}{bold}[COREWAR]{eoc} fail to load %s\n", name);
	ft_del_cpu(cpu);
	return (0);
}
