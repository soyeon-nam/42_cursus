/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 06:42:38 by snam              #+#    #+#             */
/*   Updated: 2021/06/01 23:37:50 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* concatenate fd_backup to line */
int		concat_old_backup(char **fd_backup, char **line, char *buf)
{
	int				flag;

	if (*fd_backup != 0)  /* somethings remain in fd_backup */
	{
		flag = split_nl(line, fd_backup);
		if (flag != 0)  /* read all fd_backup */
		{
			free(buf);
			if (flag == 1)
				return (1);
			else if (flag == -1)
				return (-1);
		}
	}
	else /* nothing left */
	{
		if (!(*line = (char *)malloc(1)))/* malloc null-terminated string to use make_ret_line */
		{
			free(buf);
			return (-1);
		}
		**line = 0;
	}
	return (0);
}

char		*make_ret_line(char **s1, char **s2)  /* similar to strjoin */
{
	char	*ret;

	if (!*s1 || !*s2)
		return (0);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(*s2) + 1));
	if (!ret)
		return (0);
	ft_strncpy(ret, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(ret, *s2, ft_strlen(*s1) + ft_strlen(*s2) + 1);
	free(*s1);
	free(*s2);
	*s2 = 0;
	return (ret);
}

/* divide string before \n or \0 to and concatenate fd_backup to line */
int		concat_new_buf(char **line, char **fd_backup, char **buf)
{
	int flag_nl;

	flag_nl = split_nl(fd_backup, buf);
	if (flag_nl == -1)
		return (-1);
	if (!(*line = make_ret_line(line, fd_backup)))
		return (-1);
	*fd_backup = *buf;
	*buf = 0;
	if (flag_nl == 0)
		return (0);
	return (1);
}

int		read_file(char **line, char **fd_backup, char **buf, int fd)
{
	long			read_size;
	int				ret;

	while ((read_size = read(fd, *buf, BUFFER_SIZE)) > 0)
	{
		(*buf)[read_size] = 0;
		ret = concat_new_buf(line, &fd_backup[fd], buf);
		if (ret == 1)		// meet \n
			return (1);
		else if (ret == -1)  // error
		{
			free(*buf);
			return (-1);
		}
		*buf = (char*)malloc(read_size + 1);
	}
		return (0);
}


int		get_next_line(int fd, char **line) 
{
	static char		*fd_backup[OPEN_MAX];
	char			*buf;
	//long			read_size;
	int				ret;

	if ((read(fd, "", 0) == -1) || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	if ((ret = concat_old_backup(&fd_backup[fd], line, buf)))
		return (ret);
	if ((ret = read_file(line, fd_backup, &buf, fd)))
		return (ret);
	// while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	// {
	// 	buf[read_size] = 0;
	// 	ret = concat_new_buf(line, &fd_backup[fd], &buf);
	// 	if (ret == 1)		// meet \n
	// 		return (1);
	// 	else if (ret == -1)  // error
	// 	{
	// 		free(buf);
	// 		return (-1);
	// 	}
	// 	buf = (char*)malloc(read_size + 1);
	// }
	free(fd_backup[fd]); /* EOF */
	free(buf);
	fd_backup[fd] = 0;  
	return (0);
}
