/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:21:16 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/07 17:58:12 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		take_name2(char **line, t_header *head, int fd, int i)
{
	int		j;

	j = 0;
	while ((*line)[i] != '"')
	{
		if (!(*line)[i])
		{
			head->prog_name[j++] = '\n';
			i = 0;
			free(*line);
			*line = NULL;
			if (get_next_line(fd, line) <= 0)
				ft_error("bad name format");
		}
		else
		{
			head->prog_name[j++] = (*line)[i++];
			if (j >= PROG_NAME_LENGTH)
				ft_error("name too long");
		}
	}
}

void		take_name(char **line, t_header *head, int fd, int raz)
{
	static int	only = 0;
	int			i;

	if (raz == 1)
	{
		only = 0;
		return ;
	}
	if (++only > 1)
		ft_error("only one name accept");
	i = -1;
	while ((*line)[++i] != '"')
		if (!(*line)[i])
		{
			i = 0;
			free(*line);
			*line = NULL;
			if (get_next_line(fd, line) <= 0 ||
			ft_strstr(&(*line)[i], ".comment"))
				ft_error("bad name format");
		}
	i++;
	take_name2(line, head, fd, i);
}

void		take_comment2(char **line, t_header *head, int fd, int i)
{
	int		j;

	j = 0;
	while ((*line)[i] != '"')
	{
		if (!(*line)[i])
		{
			head->comment[j++] = '\n';
			i = 0;
			free(*line);
			*line = NULL;
			if (get_next_line(fd, line) <= 0)
				ft_error("bad comment format");
		}
		else
		{
			head->comment[j++] = (*line)[i++];
			if (j >= COMMENT_LENGTH)
				ft_error("comment too long");
		}
	}
}

void		take_comment(char **line, t_header *head, int fd, int raz)
{
	static int	only = 0;
	int			i;

	if (raz == 1)
	{
		only = 0;
		return ;
	}
	if (++only > 1)
		ft_error("only one comment accept");
	i = -1;
	while ((*line)[++i] != '"')
		if (!(*line)[i])
		{
			i = 0;
			free(*line);
			*line = NULL;
			if (get_next_line(fd, line) <= 0)
				ft_error("bad comment format");
		}
	i++;
	take_comment2(line, head, fd, i);
}
