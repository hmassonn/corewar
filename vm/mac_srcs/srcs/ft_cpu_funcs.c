/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpu_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:29:11 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/06 21:55:18 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_get_code_size(int fd)
{
	char	buf[1];
	int		size;

	size = 0;
	lseek(fd, 2192, SEEK_SET);
	while (read(fd, buf, 1) > 0)
		size++;
	lseek(fd, 2192, SEEK_SET);
	return (size);
}

int		ft_get_cpu_info(int fd, t_cpu *cpu)
{
	unsigned int	magic;
	unsigned char	magic_buf[4];

	read(fd, &magic_buf, 4);
	magic = magic_buf[0];
	magic <<= 8;
	magic |= magic_buf[1];
	magic <<= 8;
	magic |= magic_buf[2];
	magic <<= 8;
	magic |= magic_buf[3];
	if (magic != COREWAR_EXEC_MAGIC)
		return (0);
	ft_bzero(cpu->name, PROG_NAME_LENGTH);
	ft_bzero(cpu->comment, COMMENT_LENGTH);
	lseek(fd, 4, SEEK_SET);
	read(fd, &cpu->name, PROG_NAME_LENGTH - 4);
	lseek(fd, PROG_NAME_LENGTH, SEEK_SET);
	read(fd, &cpu->comment, COMMENT_LENGTH - 12);
	cpu->size = ft_get_code_size(fd);
	if (cpu->size > CHAMP_MAX_SIZE)
		return (0);
	if (!(cpu->code = (unsigned char*)ft_memalloc(cpu->size)))
		exit(0);
	return (read(fd, cpu->code, cpu->size) ? 1 : 1);
}

t_cpu	*ft_new_cpu(int fd, int uid, int color)
{
	t_cpu	*cpu;

	if (!(cpu = (t_cpu*)ft_memalloc(sizeof(t_cpu))))
		exit(0);
	cpu->next = NULL;
	cpu->live = 0;
	cpu->pc = 0;
	cpu->carry = 0;
	cpu->uid = uid;
	cpu->cycle_wait = 0;
	cpu->color = color;
	if (!ft_get_cpu_info(fd, cpu))
	{
		free(cpu);
		return (NULL);
	}
	ft_bzero(cpu->reg, sizeof(cpu->reg));
	cpu->reg[0] = cpu->uid;
	return (cpu);
}

void	ft_del_cpu(t_cpu **cpu)
{
	t_cpu	*lst;
	t_cpu	*tmp;

	lst = *cpu;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		if (tmp->code)
			free(tmp->code);
		free(tmp);
	}
}

int		ft_cpu_addfront(t_cpu **cpu, int fd, int color, int uid)
{
	t_cpu	*lst;

	if (!(lst = ft_new_cpu(fd, uid, color)))
		return (0);
	lst->next = *cpu;
	*cpu = lst;
	return (1);
}
