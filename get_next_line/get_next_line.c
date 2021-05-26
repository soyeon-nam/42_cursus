/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 06:42:38 by snam              #+#    #+#             */
/*   Updated: 2021/05/27 08:07:25 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		free_alloc(char **backup, char **line)
{
	if (*backup)
		free(*backup);
	if (*line)
		free(*line);
	return (-1);
}

int		concat_backup(char **fd_backup, char **line)
{
	int				flag;

	if (*fd_backup != 0)
	{
		flag = split_nl(line, fd_backup);
		if (flag == 1)
			return (1);
		else if (flag == -1)
			return (free_alloc(fd_backup, line));
	}
	else
	{	
		if (!(*line = (char *)malloc(1)))
			return (-1);
		**line = 0;
	}
	return (0);
}

int		read_line(char **line, char **fd_backup, char *buf, int fd)
{
	int flag_nl;

	flag_nl = split_nl(&fd_backup[fd], &buf);
	if (flag_nl == -1)
		return (free_alloc(&fd_backup[fd], line));
	if (!ft_strjoin(*line, *fd_backup))
		return (-1);
	if (flag_nl == 0)
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line) 
{
	static char		*fd_backup[OPEN_MAX];
	char			buf[BUFFER_SIZE];
	unsigned int	read_size;
	int				ret;

	ret = -1;
	if (fd < 0 || !line)
		return (-1);
	if (ret == concat_backup(&fd_backup[fd], line))
		return (ret);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		ret = read_line(line, fd_backup, buf, fd);
		if (ret == 1) //\n을 만남
			return (1);
		else if (ret == -1)  //중간에 error
			return (-1);
	}
	if (read_size == 0)
	{
		fd_backup[fd] = 0;
		return (0);
	}
	free_alloc(fd_backup, line);  //if (ret = -1)
	return (-1);
}
