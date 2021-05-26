/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:10:57 by snam              #+#    #+#             */
/*   Updated: 2021/05/27 02:14:38 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		free_alloc(char **temp, char **line)
{
	if (*temp)
		free(*temp);
	if (*line)
		free(*line);
	return (-1);
}



int		affix_buf(char **sep, char **line, int *size)
{
	int		size_temp;
	char	*end;

	size_temp = 0;
	if (!sep)
	{
		end = ft_strchr(*sep, '\n');
		size_temp = *sep - end + 1;
		if (!(*line = (char *)malloc(sizeof(char) * (size_temp + 1))))
			return (0);
		ft_strncpy_until_nl(*line, *sep, size_temp + 1);
		if (!(*sep = end + 1))
			*sep = 0;
	}
	else
		if (!(*line = (char *)malloc(sizeof(char) * 1)))
			return (0);
	*size = size_temp;
	return (1);
}

char	*concat_line(char *buf, int *size, char **line, char *temp)
{
	char	*check;

	check = 0;
	ft_strncpy_until_nl(temp, *line, *size);
	free(*line);
	if (!(*line = (char *)malloc(sizeof(char) * (*size + 1))))
	{
		free(temp);
		return (-1);
	}
	ft_strncpy_until_nl(*line, temp, *size);
	free(temp);
	check = ft_strcat_until_nl(*line, buf, *size);
	if (check)
		return (check);
	if (!(temp = (char *)malloc(sizeof(char) * (*size + 1))))
		return (-1);
	return (0);
}

read_line()
{
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
			printf(buf)
			
}

int		get_next_line(int fd, char **line) 
{
	static char		buf[BUFFER_SIZE + 1];
	static char		*sep;
	char			*temp;
	size_t			size;
	size_t			read_size;

	size = 0;
	temp = (char *)malloc(sizeof(char) * (size + 1));
	if (!line || !temp || affix_buf(&sep, line, &size))
	{
		return (free_alloc(&temp, line));
	}
	*temp = 0;
	if (!sep) //affix_buf에서 \n 안만났으면 더 읽어라
		while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			size += read_size;
			if ((sep = concat_line(buf, size, line, temp)) > 0) // \n 만나서 끝남
				return (0);
			else if (sep == -1)
				return (free_alloc(&temp, line));
		}
	free(temp);
	return (0);
}

//stdin 으로 들어오는 경우는 어떤 경우?
//split 처럼 free 함수 만들어줘야 하나
// double-free X
