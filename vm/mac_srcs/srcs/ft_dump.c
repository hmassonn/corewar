/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:28:53 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/06 17:28:54 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_dump_memory(unsigned char *arena)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%02x%c", arena[i], j == 31 ? '\n' : ' ');
		i++;
		j == 31 ? j = 0 : j++;
	}
}
