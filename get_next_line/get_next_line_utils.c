#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	ret;

	ret = 0;
	while (s[ret])
		++ret;
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == 0)
		return ((char *)s);
	return (0);
}

//similar with strncpy but +chr \n
char	*ft_strncpy_until_nl(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < n && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dest[i++] = '\n';
		dest[i++] = 0;
		return (&dest[i]);
	}
	dest[i] = 0;
	return (0);
}

size_t	ft_strcat_until_nl(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dst_len;

	dst_len = ft_strlen(dst);
	i = 0;
	while (src[i] && (i + 1 < size) && src[i] != '\n')
	{
		dst[dst_len + i] = src[i];
		++i;
	}
	if (src[i] == '\n')
	{
		dest[dst_len + i++] = '\n';
		dest[dst_len + i] = 0;
		return (&src[i]);
	}
	dest[dst_len + i] = 0;
	return (0);
}
