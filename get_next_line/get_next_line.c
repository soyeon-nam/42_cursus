#include "get_next_line.h"

char	*read_line(int fd, char *buf, int *size, char **line)
{
	char	*check;

	check = 0;
	ft_strncpy_until_nl(temp, *line);
	free(*line)
	if (!(line = (char *)malloc(sizeof(char) * (size + 1))))
	{
		free(temp);
		return (0);
	}
	ft_strncpy_until_nl(*line, temp);
	free(temp);
	check = ft_strcat_until_nl(*line, buf, size);
	if (check)
		return (check);
	if (!(temp = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	return ()
}

int		affix_buf(char *buf, char **sep, char **line, int *size)
{
	int		size_temp;
	char	*end;
	if (!sep)
	{
		end = ft_strchr(*sep, '\n');
		size_temp = *sep - end + 1;
		if (!(*line = (char *)malloc(sizeof(char) * (size_temp + 1))))
			return (0);
		ft_strncpy_until_nl(line, *sep, size_temp + 1);
		if (!(*sep = end + 1))
			*sep = 0;
	}
	else
		if (!(*line = (char *)malloc(sizeof(char) * 1)))
			return (0);
	*size = size_temp;
	return (1);
}

int		get_next_line(int fd, char **line) 
{
	static char		buf[BUFFER_SIZE + 1];
	static char		*sep;
	char			*temp;
	size_t			size;
	size_t			read_size;
	
	size = 0
	temp = (char *)malloc(sizeof(char) * (size + 1));
	if (!line || !temp || affix_buf(buf, &sep, line, &size))
	{	
		free(temp);
		free(*line); //겹쳐도 됨?
		return (-1);
	}
	*temp = 0;
	if (!sep) //affix_buf에서 \n 안만났으면 더 읽어라
	{
		while (read_size = read(fd, buf, BUFFER_SIZE) > 0)
		{
			size += BUFFER_SIZE;
			if (sep = read_line(fd, buf, size, line)) // \n 만나면
				return (0);
		}
		free(temp);
	}
	free(temp);
	if ()//error
	{
		free(*line);
		return (-1);
	}
	return (0);
}


//stdin 으로 들어오는 경우는 어떤 경우?
//split 처럼 free 함수 만들어줘야 하나