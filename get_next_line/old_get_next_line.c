#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dst_len;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (src_len + size);
		i = 0;
	while ((i < size - dst_len - 1) && src[i])
	{
		dst[dst_len + i] = src[i];
		++i;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	size_src;
	unsigned int	i;

	if (!dst || !src)
		return (0);
	size_src = ft_strlen(src);
	i = 0;
	while ((i + 1 < dstsize) && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	if (dstsize != 0) 
		dst[i] = 0;
	return (size_src);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if(!ret)
		return (0);
	ft_strlcpy(ret, s1, ft_strlen(s1) + 1);
	ft_strlcat(ret, s2, ft_strlen(s1) + 1);
	return(ret);
}


void	ft_bzero(void *s, size_t n)
{
	while (n--)
	{
		*(unsigned char *)s = 0;
		++s;
	}
}


char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

char	*ft_calloc(size_t size)
{
	char	*ret;

	ret = (char *)malloc(size);
	if (!ret)
		return (0);
	ft_bzero(ret, size);
	return (ret);
}

int		cut_line(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		++i;
	if (buf[i] == '\n')
	{
		buf[i] = '\n';
		return (i);
	}
	else 
		return (-1);
}

int		get_next_line(int fd, char **line) 
{
	char	*tmp;
	char	*buf;
	char	*buf_tmp;
	int		buf_size;
	int		read_size;
	int		newline_idx;

	if (fd = 1)
	{

	}
	else if (fd > 2)
	{
		if (!(tmp = (char *)malloc(BUFFER_SIZE + 1)))
			return (-1);
		if (!(buf = (char *)malloc(1)))
			return (-1);
		*tmp = 0;
		*buf = 0;
		buf_size = 0;
		while ((read_size = read(fd, tmp, BUFFER_SIZE)) > 0 && ft_strchr(,tmp)/*뉴라인 없음*/)
		{
			
			buf_size += read_size;
			newline_idx = cut_line(tmp);
			buf = ft_calloc(buf_size + 1);

			if (newline_idx == -1)
			{

			}
			buf = ft_strjoin(buf, tmp);
			free(buf);
			free(tmp);
			tmp = ft_calloc(buf_size + 1);
		}
	}
	*line = buf;
	free(tmp);
	return ();
}


int	main()
{
	i = 0;
	while (get_next_line(3, &str))
	{
		printf("%i : %s", str);
		i++;
	}
	
}
