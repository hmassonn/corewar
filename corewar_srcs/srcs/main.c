/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <clanier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 19:56:51 by clanier           #+#    #+#             */
/*   Updated: 2017/03/07 12:01:50 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_get_player_index(char **av, int *i, int *j)
{
	*i = 1;
	*j = 0;
	while (av[*i] && av[*i][0] == '-' && ++(*j))
	{
		if (!ft_strcmp("-n", av[*i]) && (*j)--)
			break ;
		if (!ft_strcmp("-dump", av[*i]) && ++(*j))
			(*i)++;
		(*i)++;
	}
}

int			ft_get_players(char **av, t_cpu **cpu)
{
	int				i;
	int				j;
	int				fd;
	long long int	n;

	ft_get_player_index(av, &i, &j);
	fd = 0;
	while (av[i])
	{
		if (i - j > 4)
			return (ft_bad_usage(cpu, i - j));
		n = (!ft_strcmp("-n", av[i]) && (j += 2) && ++i) ?
		ft_atoi(av[i++]) : 0x100000000 - i + j;
		if ((fd = open(av[i], O_RDONLY)) >= 0)
		{
			if (!ft_cpu_addfront(cpu, fd, i - j, n))
				return (ft_player_error(cpu, av[i], fd));
		}
		else
			return (ft_player_error(cpu, av[i], 0));
		close(fd);
		i++;
	}
	return (fd ? 1 : ft_bad_usage(cpu, 0));
}

void		ft_parse_opt(char **av, int i, int j, char *opt)
{
	while (av[i][j])
	{
		if (av[i][j] == 'p')
			*opt |= 0b00000001;
		else if (av[i][j] == 'g')
			*opt |= 0b00000010;
		else if (av[i][j] == 'w')
			*opt |= 0b00000100;
		else if (av[i][j] == 'c')
			*opt |= 0b00001000;
		else if (av[i][j] == 'v')
			*opt |= 0b00010000;
		else if (av[i][j] == 'q')
			*opt |= 0b00100000;
		else if (av[i][j] == 'm')
			*opt |= 0b01000000;
		j++;
	}
}

void		ft_get_opt(char *opt, int *dump, char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	*opt = 0;
	*dump = -1;
	while (ac > i && av[i][0] == '-' && ft_strcmp("-n", av[i]))
	{
		j = 1;
		if (ac > i + 1 && !ft_strcmp("-dump", av[i]) && ++i)
			*dump = ft_atoi(av[i]);
		else
			ft_parse_opt(av, i, j, opt);
		i++;
	}
}

int			main(int ac, char **av)
{
	t_cpu	*cpu;
	t_mars	*mars;
	char	opt;
	int		dump;

	ft_get_opt(&opt, &dump, av, ac);
	cpu = NULL;
	if (!ft_get_players(av, &cpu))
		return (0);
	mars = ft_new_mars(&cpu, opt, dump);
	if (opt & 0b00000100)
		ft_ncurses_init();
	ft_run_mars(mars, cpu);
	if (opt & 0b00000100)
	{
		getch();
		endwin();
	}
	ft_del_mars(mars);
}
