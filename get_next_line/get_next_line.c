/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 06:42:38 by snam              #+#    #+#             */
/*   Updated: 2021/05/29 16:47:55 by snam             ###   ########.fr       */
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
			return (1);
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

int		read_line(char **line, char **fd_backup, char *buf)
{
	int flag_nl;

	flag_nl = split_nl(fd_backup, &buf);
	if (flag_nl == -1)
		return (-1);
	if (!(*line = ft_strjoin(*line, *fd_backup)))
		return (-1);
	*fd_backup = buf;
	if (flag_nl == 0)
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line) 
{
	static char		*fd_backup[OPEN_MAX];
	char			*buf;
	unsigned int	read_size;
	int				ret;
	
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	ret = -1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((ret = concat_backup(&fd_backup[fd], line, buf)))
		return (ret);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = 0;
		ret = read_line(line, &fd_backup[fd], buf);
		if (ret == 1)//\n을 만남
		{ 
			//free(buf);
			return (1);
		}
		else if (ret == -1)  //중간에 error
		{
			free(buf);
			return (-1);
		}
	}
	fd_backup[fd] = 0;//read_size == 0
	free(buf);
	return (0);
}

//한 줄에 한 가지만 있는 경우,줄이 더 이상 나오지 않음
//마지막 줄이 나오지 않음
