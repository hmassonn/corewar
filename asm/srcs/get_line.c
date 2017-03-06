/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:38:52 by hmassonn          #+#    #+#             */
/*   Updated: 2017/02/28 08:37:01 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int		check_line(char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

void	use_line(char *line, t_inst **champ, t_header *head, int x[2])
{
	int		i;
	int		fd;

	i = x[0];
	fd = x[1];
	if (line != NULL && line[0] && check_line(line) == 1)
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (!ft_strncmp(&line[i], NAME_CMD_STRING, NAMELEN))
			take_name(&line, head, fd, 0);
		else if (!ft_strncmp(&line[i], COMMENT_CMD_STRING, COMMENTLEN))
			take_comment(&line, head, fd, 0);
		else
			*champ = fill_champ(line, *champ, 0);
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

void	get_line(int fd, t_inst **champ, t_header *head)
{
	char		*line;
	int			i;
	int			ret;

	line = NULL;
	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
		use_line(line, champ, head, (int[2]){i, fd});
	if (!head->prog_name[0])
		ft_error("you need a name");
	*champ = fill_champ(line, *champ, 1);
	if (ret < 0)
		ft_error("Lexical error");
	if ((head->prog_size = calc_prog_size(*champ)) > CHAMP_MAX_SIZE)
		ft_error("champ is too large");
	take_name(NULL, NULL, 0, 1);
	take_comment(NULL, NULL, 0, 1);
}
