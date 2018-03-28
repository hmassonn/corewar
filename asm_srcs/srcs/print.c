/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:19:11 by basle-qu          #+#    #+#             */
/*   Updated: 2017/02/26 18:25:09 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

extern t_op g_op_tab[];

void	print_int(unsigned int nb, int fd)
{
	ft_putchar_fd(nb >> 24, fd);
	ft_putchar_fd(nb >> 16, fd);
	ft_putchar_fd(nb >> 8, fd);
	ft_putchar_fd(nb, fd);
}

void	print_half_int(unsigned int nb, int fd)
{
	ft_putchar_fd(nb >> 8, fd);
	ft_putchar_fd(nb, fd);
}

void	print_progname(t_header *head, int fd)
{
	int i;

	i = 0;
	while (head->prog_name[i] && i < PROG_NAME_LENGTH + 1)
	{
		ft_putchar_fd(head->prog_name[i], fd);
		i++;
	}
	while (i < PROG_NAME_LENGTH + 1)
	{
		ft_putchar_fd(0, fd);
		i++;
	}
	while (i % 4)
	{
		ft_putchar_fd(0, fd);
		i++;
	}
}

void	print_comment(t_header *head, int fd)
{
	int i;

	i = 0;
	while (head->comment[i] && i < COMMENT_LENGTH + 1)
	{
		ft_putchar_fd(head->comment[i], fd);
		i++;
	}
	while (i < COMMENT_LENGTH + 1)
	{
		ft_putchar_fd(0, fd);
		i++;
	}
	while (i % 4)
	{
		ft_putchar_fd(0, fd);
		i++;
	}
}

void	print_args_value(char **args, int fd)
{
	int size;
	int i;

	size = 0;
	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		size += arg_binary(args[i]) << (6 - (i * 2));
		i++;
	}
	ft_putchar_fd(size, fd);
}
