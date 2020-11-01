/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoria-g <isoria-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 10:51:45 by isoria-g          #+#    #+#             */
/*   Updated: 2020/02/17 15:02:22 by isoria-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		saveline(char **st, char ***line)
{
	char	*tem;

	**line = ft_substr(*st, 0, ft_streol(*st));
	tem = ft_strdup(*st);
	free(*st);
	*st = NULL;
	*st = ft_substr(tem, ft_streol(tem) + 1, ft_strlen(tem) - ft_streol(tem));
	free(tem);
	tem = NULL;
	return (1);
}

int		readline(char *buf, char **st, int fd)
{
	int		ret;
	char	*temp;

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = ft_strdup(*st);
		free(*st);
		*st = NULL;
		*st = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_streol(*st) != -1)
			break ;
	}
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	static char	*st;
	char		*buf;

	ret = 1;
	if ((buf = malloc(BUFFER_SIZE + 1)) == NULL || fd == -1 || line == NULL ||
		BUFFER_SIZE == 0 || read(fd, buf, 0) == -1)
	{
		free(buf);
		return (-1);
	}
	if (st == NULL)
		st = ft_strdup("");
	if (ft_streol(st) == -1)
		ret = readline(buf, &st, fd);
	free(buf);
	if (ret == 0)
	{
		*line = ft_strdup(st);
		free(st);
		st = NULL;
		return (0);
	}
	return (saveline(&st, &line));
}
