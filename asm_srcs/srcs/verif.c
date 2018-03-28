/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:18:27 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/02 17:54:14 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

extern t_op	g_op_tab[];

void		check_label_dir(char *para)
{
	int			i;
	int			j;
	int			count;
	static char	label[] = LABEL_CHARS;

	i = 1;
	count = 0;
	while (para[i])
	{
		j = 0;
		while (label[j])
		{
			if (label[j] == para[i])
				count++;
			j++;
		}
		i++;
	}
	if (i == 1 || count < i - 1)
		ft_error("Bad label direct");
}

void		check_dir(int t, int npara, char **para)
{
	int		i;

	if ((g_op_tab[t].arguments[npara] & T_DIR) != T_DIR)
		ft_error("Bad argument direct");
	if (para[npara][1] == LABEL_CHAR)
	{
		check_label_dir(&para[npara][1]);
		return ;
	}
	if (para[npara][1] == '-' || ft_isdigit(para[npara][1]))
	{
		i = 0;
		while (para[npara][++i])
		{
			if (!ft_isdigit(para[npara][i]) && para[npara][i] != '-')
			{
				ft_putendl(&para[npara][i]);
				ft_error("Bad direct digit");
			}
		}
		if (i == 1)
			ft_error("Bad direct digit empty");
		return ;
	}
	ft_error("Bad argument direct unknow");
}

void		check_reg(int t, int npara, char **para)
{
	int		i;

	i = 1;
	if ((g_op_tab[t].arguments[npara] & T_REG) != T_REG)
		ft_error("Bad argument register");
	while (para[npara][i])
	{
		if (!ft_isdigit(para[npara][i]))
			ft_error("Bad register number");
		i++;
	}
	if (i == 1)
		ft_error("Bad register empty");
	if ((i = ft_atoi(&para[npara][1])) > REG_NUMBER || i < 1)
		ft_error("Bad register (r1 <–> rx avec x = REG_NUMBER)");
}

void		check_ind(int t, int npara, char **para)
{
	int		i;

	i = 0;
	if ((g_op_tab[t].arguments[npara] & T_IND) != T_IND)
		ft_error("Bad argument indirect");
	while (para[npara][i])
	{
		if (!ft_isdigit(para[npara][i]) && para[npara][i] != '-')
			ft_error("Bad indirect number");
		i++;
	}
	if (i == 0)
		ft_error("Bad argument indirect empty");
}

int			verif_params(char *name, char **para)
{
	int		t;
	int		npara;

	npara = -1;
	if (!para)
		ft_error("Bad arguments");
	check_t(&t, name);
	while (para[++npara])
	{
		if (npara >= g_op_tab[t].nb_arguments)
			ft_error("Bad number of arguments");
		if (para[npara][0] == LABEL_CHAR)
			check_label_ind(t, npara, para);
		else if (para[npara][0] == DIRECT_CHAR)
			check_dir(t, npara, para);
		else if (para[npara][0] == 'r')
			check_reg(t, npara, para);
		else if (para[npara][0] == '-' || ft_isdigit(para[npara][0]))
			check_ind(t, npara, para);
		else
			ft_error("Bad argument unknow type");
	}
	if (npara != g_op_tab[t].nb_arguments)
		ft_error("Bad argument number");
	return (1);
}
