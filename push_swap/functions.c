#include "push_swap.h"

static int		ft_isspace(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int				sign;
	unsigned long	ret;

	while (ft_isspace(*str))
		++str;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	ret = 0;
	while ('0' <= *str && *str <= '9')
	{
		ret = (ret * 10) + (*str - '0');
		++str;
	}
	if (ret > (unsigned long)__LONG_MAX__ && sign == 1)
		return (NULL);
	else if (ret > (unsigned long)__LONG_MAX__ + 1 && sign == -1)
		return (NULL);
	if 
	return ((int)ret * sign);  //(ret * sign)
}
//인티져범위 넘는다면 return null;




static	char			**free_malloc(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		++i;
	}
	free(str);
	return (0);
}
//고칠거

static unsigned int		count_word(char *s, char c)
{
	unsigned int count;

	count = 0;
	while (*s)
	{
		while (*s == ' ')
			++s;
		if (!*s)
			break ;
		while (*s && *s != ' ')
			++s;
		++count;
	}
	return (count);
}

static char				*slpit_word(char *start, int num)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char) * (num + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (i < num)
	{
		ptr[i] = start[i];
		++i;
	}
	ptr[i] = 0;
	return (ptr);
}

char					**ft_split(char const *s)
{
	char			**str;
	char			*start;
	unsigned int	word_size;
	unsigned int	i;

	if (!s)
		return (0);
	word_size = count_word((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (word_size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < word_size)
	{
		while (*s == ' ')
			++s;
		start = (char *)s;
		while (0 <= *s && *s <= 9)
			++s;
		if (*s != ' ')
			return (free_malloc(str));
		if (!(str[i] = slpit_word(start, s - start)))
			return (free_malloc(str));
		++i;
	}
	str[i] = 0;
	return (str);
}