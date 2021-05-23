/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 00:59:30 by marvin            #+#    #+#             */
/*   Updated: 2021/05/23 00:59:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"




char	*split_newline()
{

}



char	*read_line(int fd)
{

}

int		get_next_line(int fd, char **line) 
{
	static char		buf[BUFFER_SIZE + 1];
	char			*temp;
	char			**split_by_newline;
	int				ret;
	size_t			size;

	size = 0;
	temp = (char *)malloc(sizeof(char) * (size + 1));
	*line = (char *)malloc(sizeof(char) * (size + 1));
	*temp = 0;
	**line = 0;
	if ()
	{

	}
	while (ret = read(fd, buf, BUFFER_SIZE) > 0)
	{
		size += BUFFER_SIZE;
		strcpy(temp, *line);
		free(*line)
		line = (char *)malloc(sizeof(char) * (size + 1));
		strcpy(*line, temp);
		free(temp);
		if ((split_by_newline = gnl_split(buf, '\n')) > 0)
		{
			ft_strlcat
			break;
		}
		else if (split_by_newline = -1)
			return (-1);
		strlcat(*line, buf, size);
		temp = (char *)malloc(sizeof(char) * (size + 1));
	}
	if (ret < 0)
		return (-1);
	return (0);
}

//stdin 으로 들어오는 경우는 어떤 경우?
//split 처럼 free 함수 만들어줘야 하나