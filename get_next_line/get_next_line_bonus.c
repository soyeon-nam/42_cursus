/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 06:42:38 by snam              #+#    #+#             */
/*   Updated: 2021/06/01 21:22:53 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		concat_backup(char **fd_backup, char **line, char *buf)
{
	int				flag;

	if (*fd_backup != 0)
	{
		flag = split_nl(line, fd_backup);
		if (flag == 1)
		{
			free(buf);
			return (1);
		}
		else if (flag == -1)
		{
			free(buf);
			return (-1);
		}
	}
	else
	{	
		if (!(*line = (char *)malloc(1)))
			return (-1);
		**line = 0;
	}
	return (0);
}

int		read_line(char **line, char **fd_backup, char **buf)
{
	int flag_nl;

	flag_nl = split_nl(fd_backup, buf);
	if (flag_nl == -1)
		return (-1);
	if (!(*line = ft_strjoin(line, fd_backup)))
		return (-1);
	*fd_backup = *buf;
	*buf = 0;
	if (flag_nl == 0)
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line) 
{
	static char		*fd_backup[OPEN_MAX];
	char			*buf;
	long			read_size;
	int				ret;

	if ((read(fd, "", 0) == -1) || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	if ((ret = concat_backup(&fd_backup[fd], line, buf)))
		return (ret);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = 0;
		ret = read_line(line, &fd_backup[fd], &buf);
		if (ret == 1)		//\n을 만남
			return (1);
		else if (ret == -1)  //중간에 error
		{
			free(buf);
			return (-1);
		}
		buf = (char*)malloc(read_size + 1);
	}
	if (read_size == -1)
	{
		free(buf);
		return (-1);
	}
	free(fd_backup[fd]);
	free(buf);
	fd_backup[fd] = 0;//read_size == 0
	return (0);
}
